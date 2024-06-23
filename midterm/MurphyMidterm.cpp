//Cameron Murphy Midterm
//CIS1202:201
#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
#include<stdio.h>
#include<sort.h>
using namespace std;

    //each lift structure represents a lift, which will have a name and sessions.
    //a session is 1. a weight and 2. sets. Sets are for how many times a new rep group was started.
    //The weight vector and the row column of the reps vector are parallel. So session 2 == weigh[1] and also reps[1][]. This is a session.
struct Lift{
    string name;
    vector<int> weight;
    vector<vector<int>> reps;
};
    //prototypes
        //adding data
void addLift(vector<Lift>&);
void addSession(vector<Lift>&);
void addVolume(Lift&);

        //displaying data
void displayLifts(vector<Lift>);
void displayVolume(vector<Lift>);
void displaySorted(vector<Lift>);
void explain();

        //utilities
int searchLifts(vector<Lift>, string);
Lift copyLift(vector<Lift>);
void sortLifts(vector<Lift>&);
void parallelSort (vector<int>&,vector<vector<int>>&);
void swap(string&, string&);

int main(){
    vector<Lift> userLifts; //holds users individual lifts
    int userOption;
    
    do{
        printf("\n1.Add to your lift list \n2.Enter a session for a lift \n3.Display your lift list \n4.Show volume of a lift by session \n5.Show volume of a lift by upward trend \n6.show explinations\n7.exit\n>>");
        userOption = userValidation("Enter a number 1 to 7",1,7);
        switch (userOption){
            case 1: addLift(userLifts);
            break;
            case 2: addSession(userLifts);
            break;
            case 3: displayLifts(userLifts);
            break;
            case 4: displayVolume(userLifts);
            break;
            case 5: displaySorted(userLifts);
            break;
            case 6: explain();
        }
    }while (userOption != 7);
    return 0;
}

/************************************************************************************
 * **********************                              ******************************
 * **********************Functions for adding Lift data******************************
 * **********************                              ******************************
 * **********************************************************************************
 */

    //add a new Lift structure. This function only fills the name of a Lift structure and adds it to the Lift vector, sorting to ensuring they are alphabetical
void addLift(vector<Lift>& userLifts){
    Lift newLift; 
    string userLiftName;
    int exists;
        //prompt user for a Lift name
    printf("Enter a new lift below\n>>");
    userLiftName = stringValidation("Enter a valid excercise",5,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
        //search our Lift array to make sure that Lift doesn't already exist in our database
    exists = searchLifts(userLifts, userLiftName);
        if (exists > -1)
            printf("The Lift %s already exists.\n", userLiftName.c_str());
        else{
            //we are sure this is a new Lift so we stick the name in our temp Lift structure and push it into our array
            newLift.name = userLiftName;
            userLifts.push_back(newLift);
            //whenever a new Lift is added we sort it alphabetically
            sortLifts(userLifts);
        }
}

    //this function asks the user to enter a lift and after making sure it exists, creates a session by calling addVolume, once
    //addVolume ends, it can be called as many times as needed
void addSession(vector<Lift>& userLifts){
    printf("Choose a lift for this session\n>");
    displayLifts(userLifts);
    printf("\n\n>>");
    string userLiftName = stringValidation("Enter a valdid lift",4,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
    int liftPOS = searchLifts(userLifts, userLiftName);

    if (liftPOS == -1) //illegal position means lift does not exist
        printf("Lift not found. If you have not added it to the database please do so through option 1.\n\n");
    else{
        int userOption;
        do{
            printf("Press 1 to enter a session or 2 to exit\n>>");
            userOption = userValidation("1 for a set, 2 to exit\n>>",1,2);
            if (userOption == 1){
                addVolume(userLifts[liftPOS]);
            }
        }while (userOption != 2);
    }
}
    //when an actual lift structure is taken from its vector and given to addVolume we can add as many reps as necessary for the set
void addVolume(Lift& Lift){
    int userWeight = 0;
    int userReps = 0;
    int userOption = 0;
    printf("Enter Weight >> ");
    userWeight = userValidation("What do you live in the moon?", "Okay, Arnold, the girl at the smithson isn't watching\nEnter a weight",0,900);
    Lift.weight.push_back(userWeight); //push the weight vector
    Lift.reps.push_back({}); //since the reps row is parallel to the weight vector we need to add a row
    int repPOS = (Lift.weight.size())-1; //the vector to store reps will always be the last one
    do{
        printf("\nEnter Reps >> ");
        userReps = userValidation("Enter a valid rep range",1,400);
        Lift.reps[repPOS].push_back(userReps);
        printf("\nAdd another set? 1.Yes 2.No\n>>");
        userOption = userValidation("Enter 1 for yes or a 2 for no",1,2);
    }while(userOption !=2);
}

/************************************************************************************
 * **********************                                      **********************
 * **********************Functions for searching and displaying**********************
 * **********************                                      **********************
 * **********************************************************************************
 */


    //displays a list of saved Lifts to the user
void displayLifts(vector<Lift> userLifts){
    printf("\n\nYour lifts: \n");
    
    for (int count = 0; count < userLifts.size(); count++){
        printf("%s\n", userLifts[count].name.c_str());
    }
    printf("\n\n");
}


    //checks if lift exists, then loops through lift and then each reps for a lift, each loops of a weight 
    //and reps is by nature a session, each loop of a rep count is by nature a set
void displayVolume(vector<Lift> userLifts){
    string userLiftName;
    int liftPOS;
    printf("\n\nWhich lift would you like to display?\n>>");
    userLiftName = stringValidation("Enter a valid lift", 5,30);
    liftPOS = searchLifts(userLifts, userLiftName);

    if (liftPOS == -1)
        printf("That lift was not found.\n\n");
    else{
        printf("%s",(userLifts[liftPOS].name.c_str())); //lift name
        for (int sessionCount = 0; sessionCount < userLifts[liftPOS].weight.size(); sessionCount++){//outer for loop displays session (count) and weight
            printf("\n\nSession %d:\n",sessionCount + 1);
            printf("Weight: %dlbs\nReps:",(userLifts[liftPOS].weight[sessionCount]));
            for(int repCount = 0;repCount < userLifts[liftPOS].reps[sessionCount].size();repCount++){ //shows sets (each set of reps) for each session
                printf("%d ", userLifts[liftPOS].reps[sessionCount][repCount]);
            }
        }
    }
}
    //This function copies the users lift data to a new Lift (we want the original data to stay in the same orde so the user can still see volume by session)
    //then sorts the weight and rep member in parallel, then it targets each set for sorting with a basic selection sort
    //it then uses the usal nested for loop to print each weight and set
void displaySorted(vector<Lift>userLifts){
   Lift sortedLift = copyLift(userLifts); //we don't want to change the original vector so the data stays in tact
   parallelSort(sortedLift.weight,sortedLift.reps); //sorts weight and 2d vector in parallel
   for (int weightCount = 0; weightCount < sortedLift.weight.size(); weightCount++){
    for (int repCount = 0; repCount < sortedLift.reps[weightCount].size(); repCount++){
        selectionSort(sortedLift.reps[weightCount]);
    } 
   }

    //This nested loop starts looping through the weight vector first and since these are parallel we can use the weight counter
    //to select the proper row for our reps vector
   printf("%s\n",(sortedLift.name.c_str())); //lift name
   for (int weightCount = 0; weightCount < (sortedLift.weight.size());weightCount++){
    printf("%d:\n", sortedLift.weight[weightCount]);
    for (int repCount = 0; repCount < (sortedLift.reps[weightCount].size()); repCount++){
        printf("< %d > ",sortedLift.reps[weightCount][repCount]);
    }
    printf("\n");
   }
}

void explain(){
    printf("If you have not entered any lift data yet, use option 1 to add a lift to your lift list\n");
    printf("USe option 2 to add a lift session choosing from your existing lifts.\n");
    printf("Option 3 will display a list of all your lifts.\n");
    printf("Use options 4 to show sets by session, or option 5 to show the upward trend of weight with sets and reps.\n");
}


/************************************************************************************
 * **********************                                      **********************
 * **********************         utility functions            **********************
 * **********************                                      **********************
 * **********************************************************************************
 */

    //Used by functions to check if a lift exists
int searchLifts(vector<Lift> userLifts, string liftName){
        //loop through Lift vector to find our Lift
    for (int count = 0; count < userLifts.size(); count++){
        if (liftName == userLifts[count].name){
            return count;
        }
    }
    return -1; //Lift was not found
}

    //Takes a Lift structure then copies it )(name, weight vector, 2D rep vector) and returns the copy
Lift copyLift(vector<Lift>userLifts){
    string userLiftName;
    int liftPOS; //
    Lift copiedLift;

    printf("Which sorted lift would you like to display?\n>>");
    userLiftName = stringValidation("Enter a valid lift", 5,30);
    liftPOS = searchLifts(userLifts, userLiftName); //make sure the lift exists

    if (liftPOS == -1)
        printf("That lift was not found.\n\n");
    else{
        copiedLift.name = userLifts[liftPOS].name; //copy name and then weight by simply pushing
        for (int weight : userLifts[liftPOS].weight){
            copiedLift.weight.push_back(weight);
        }
        for (vector<int> sets : userLifts[liftPOS].reps){ //use for each loop to create a row for each set then fill
            copiedLift.reps.push_back({});
            for (int reps : sets){
                copiedLift.reps.back().push_back(reps);
            }
        }
    }
    return copiedLift;
}
    //simple alphabet sorting function for Lift vectors, it checks only the name members of our Lift structure but it swaps entire structures
void sortLifts(vector<Lift>& userLifts){
    for (int start = 0; start < (userLifts.size() - 1); start++){
            int minIndex = start;
            string minValue = userLifts[start].name;
                for (int index = start + 1; index < userLifts.size(); index++){
                        if (userLifts[index].name < minValue){
                                minValue = userLifts[index].name;
                                minIndex = index;
                        }
                }
                swap (userLifts[minIndex], userLifts[start]);
        }
} 

    //The sort function is put here since it is pretty specifioc to this case, sorting a vector, then sorting a 2d vector column in parallel to it
void parallelSort (vector<int>& list,vector<vector<int>>& parallel){
        int size = list.size()-1;
        for (int start = 0; start < (size - 1); start++){
                int minIndex = start;
                float minValue = list[start];
                for (int index = start + 1; index < size; index++){
                        if (list[index] < minValue){
                                minValue = list[index];
                                minIndex = index;
                        }
                }
                swap (list[minIndex], list[start]);
                swap (parallel[minIndex], parallel[start]); //extra swap is done
        }
}

    //swap function for sort
void swap (string& a, string& b){
        string temp = a;
        a = b;
        b = temp;
} 

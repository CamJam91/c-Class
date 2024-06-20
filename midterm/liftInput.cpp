#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
#include<stdio.h>
#include<sort.h>
using namespace std;

    //each lift structure represents a lift, which will have a name and sessions.
    //a session is 1. a weight and 2. sets. Sets are for how many reps was the movement done. The number of sets can vary
    //The weight vector and the row column of the reps vector are parallel. So session 2 == weigh[1] and also reps[1][]. This is a session
struct Lift{
    string name;
    vector<int> weight;
    vector<vector<int>> reps;
};
    //prototypes
void addLift(vector<Lift>&);
int searchLifts(vector<Lift>, string);
void addSession(vector<Lift>& userLifts);
void addVolume(Lift&);
void displayLifts(vector<Lift>);
void sortLifts(vector<Lift>&);
void swap(string&, string&);
void displayVolume(vector<Lift>);

int main(){
    vector<Lift> userLifts;
    int userOption;
    
    do{
        printf("\n1.Enter a new Lift to your database \n2.Enter workout stats for a Lift from your list \n3.Display all your Lifts \n4.Show stats for a Lift \n5.exit\n>>");
        userOption = userValidation("Enter a number 1 to 3",1,4);
        switch (userOption){
            case 1: addLift(userLifts);
            break;
            case 2: addSession(userLifts);
            break;
            case 3: displayLifts(userLifts);
            break;
            case 4: displayVolume(userLifts);
        }
    }while (userOption != 5);
    return 0;
}

/************************************************************************************
 * **********************                              ******************************
 * **********************Functions for adding Lift data******************************
 * **********************                              ******************************
 * **********************************************************************************
 */

    //add anew Lift structure. This function only fills the name of a Lift structure and adds it to the Lift vector, ensuring they are alphabetical
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
        if (exists == 1)
            printf("The Lift %s already exists.\n", userLiftName.c_str());
        else{
            //we are sure this is a new Lift so we stick the name in our temp Lift structure and push it inot our array
            newLift.name = userLiftName;
            userLifts.push_back(newLift);
            //whenever a new Lift is added we sort it alphabetically
            sortLifts(userLifts);
        }
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
    //Two functions add the actual weight and reps to a saved lift, this checks for a lifts existance, 
    //then asks the user to enter a session (weight and sets) then calls the addVolume to actually get the metrics
    //for each session
void addSession(vector<Lift>& userLifts){
    printf("What lift would you like to add a session to? >>\n");
    string userLiftName = stringValidation("Enter a valdid lift",4,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
    int liftPOS = searchLifts(userLifts, userLiftName);

    if (liftPOS == -1)
        printf("Lift not found. If you have not added it to the database please do so through option 1. \n You Can also use option 2 to display your lift database\n\n");
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
    //adds the actual weight (only one weight metric per session), and sets for that weight, since the number of sets can vary
    //the user needs continual prompting until they are done, we can then go back to our addsession functions and add another
    //session or quit
void addVolume(Lift& Lift){
    int userWeight = 0;
    int userReps = 0;
    int userOption = 0;
    printf("Enter Weight >> ");
    userWeight = userValidation("What do you live in the moon?", "Okay, Arnold, the girl at the smithson isn't watching\nEnter a weight",0,900);
    Lift.weight.push_back(userWeight);
    Lift.reps.push_back({});
    int repPOS = (Lift.weight.size())-1;
    do{
        printf("\nEnter Reps >> ");
        userReps = userValidation("Enter a valid rep range",1,400);
        Lift.reps[repPOS].push_back(userReps);
        printf("\nAdd another set? 1.Yes 2.No");
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
    printf("\n\nHere are your lifts: \n");
    
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
    printf("Which lift would you like to display?");
    userLiftName = stringValidation("Enter a valid lift", 5,30);
    liftPOS = searchLifts(userLifts, userLiftName);

    if (liftPOS == -1)
        printf("That lift was not found.\n\n");
    else{
        printf("%s",(userLifts[liftPOS].name.c_str())); //lift name
        for (int sessionCount = 0; sessionCount < userLifts[liftPOS].weight.size(); sessionCount++){//outer for loop displays session (count) and weight
            printf("\nSession %d:\n",sessionCount + 1);
            printf("Weight: %dlbs\nReps:",(userLifts[liftPOS].weight[sessionCount]));
            for(int repCount = 0;repCount < userLifts[liftPOS].reps[sessionCount].size();repCount++){ //shows sets (each set of reps) for each session
                printf("%d ", userLifts[liftPOS].reps[sessionCount][repCount]);
            }
        }
    }
}

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

    //swap function for sort
void swap (string& a, string& b){
        string temp = a;
        a = b;
        b = temp;
} 

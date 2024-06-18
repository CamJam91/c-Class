#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
#include<stdio.h>
#include<sort.h>
using namespace std;

    //each lift has a name and a 2d vector called voume that represents weight and reps
struct lift{
    string name;
    vector<vector<int>> volume;
};
    //prototypes
void addLift(vector<lift>&);
int searchLifts(vector<lift>, string);
void addVolume(vector<lift>&);
void displayLifts(vector<lift>);
void sortLifts(vector<lift>&);
void swap(string&, string&);
void displayVolume(vector<lift>);

int main(){
    vector<lift> userLifts;
    int userOption;
    
    do{
        printf("1.Enter a new lift to your database \n2.Enter workout stats for a lift from your list \n3.Display all your lifts \n4.Show stats for a lift \n5.exit\n>>");
        userOption = userValidation("Enter a number 1 to 3",1,4);
        switch (userOption){
            case 1: addLift(userLifts);
            break;
            case 2: addVolume(userLifts);
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
 * **********************Functions for adding lift data******************************
 * **********************                              ******************************
 * **********************************************************************************
 */

    //add anew lift structure. This function only fills the name of a lift structure and adds it to the lift vector, ensuring they are alphabetical
void addLift(vector<lift>& userLifts){
    lift newLift; 
    string userLiftName;
    int exists;
        //prompt user for a lift name
    printf("Enter a new lift below\n>>");
    userLiftName = stringValidation("Enter a valid excercise",5,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
        //search our lift array to make sure that lift doesn't already exist in our database
    exists = searchLifts(userLifts, userLiftName);
        if (exists == 1)
            printf("The lift %s already exists.\n", userLiftName.c_str());
        else{
            //we are sure this is a new lift so we stick the name in our temp lift structure and push it inot our array
            newLift.name = userLiftName;
            userLifts.push_back(newLift);
            //whenever a new lift is added we sort it alphabetically
            sortLifts(userLifts);
        }
}

    //fills the volume vector of a lift, this is not called when a lift is made, it is called when a new session of a lift is added
void addVolume(vector<lift>& userLifts){
    printf("What lift would you like to add a session to? >>\n");
    string userLiftName = stringValidation("Enter a valdid lift",5,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
    int liftPOS = searchLifts(userLifts, userLiftName);

    if (liftPOS == -1)
        printf("Lift not found. If you have not added it to the database please do so through option 1. \n You Can also use option 2 to display your lift database\n\n");
    else{
        int userOption;
        do{
            printf("Press 1 to enter a set or 2 to exit\n>>");
            userOption = userValidation("1 for a set, 2 to exit\n>>",1,2);
            if (userOption == 1){
                int userWeight = 0;
                int userReps = 0;
                printf("Enter Weight >> ");
                userWeight = userValidation("What do you live in the moon?", "Okay, Arnold, the girl at the smithson isn't watching\nEnter a weight",0,900);
                printf("\nEnter Reps >> ");
                userReps = userValidation("Enter a valid rep range",1,400);

                userLifts[liftPOS].volume.push_back({userWeight, userReps}); //rows are weight and columns are reps
                }
        }while (userOption != 2);
    }
}
    //simple alphabet sorting function for lift vectors, it checks only the name members of our lift structure but it swaps entire structures
void sortLifts(vector<lift>& userLifts){
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

/************************************************************************************
 * **********************                                      **********************
 * **********************Functions for searching and displaying**********************
 * **********************                                      **********************
 * **********************************************************************************
 */


    //displays a list of lifts to the user
void displayLifts(vector<lift> userLifts){
    printf("\n\nHere are your lifts: \n");
    
    for (int count = 0; count < userLifts.size(); count++){
        printf("%s\n", userLifts[count].name.c_str());
    }
    printf("\n\n");
}

void displayVolume(vector<lift> userLifts){
    string userLiftName;
    int liftPOS;
    printf("Which lift would you like to display?");
    userLiftName = stringValidation("Enter a valid lift", 5,30);
    liftPOS = searchLifts(userLifts, userLiftName);
    if (liftPOS == -1)
        printf("That lift was not found.\n\n");
    else{
        printf("%s\n",userLifts[liftPOS].name.c_str());
        printf("%-20s %20s", "Weight", "Reps\n");
        for(int count = 0; count < (userLifts[liftPOS].volume.size()); count++){
            printf("%-20d %20d\n", userLifts[liftPOS].volume[count][count], userLifts[liftPOS].volume[count][count+1]);
        }
    }

    
}

int searchLifts(vector<lift> userLifts, string liftName){
        //loop through lift vector to find our lift
    for (int count = 0; count < userLifts.size(); count++){
        if (liftName == userLifts[count].name){
            return count;
        }
    }
    return -1; //lift was not found
}

void swap (string& a, string& b){
        string temp = a;
        a = b;
        b = temp;
} 

#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
#include<stdio.h>
using namespace std;

    //each lift has a name, and a nested voume structure, volume is the weight lifted and for how many reps that weight is
    //lifted, they are inseperable and each entry must represent a different session, therefore volume is a vector
struct volume{
    int weight;
    int reps;

};
struct lift{
    string name;
    vector<volume> liftVolume;
};

void addLift(vector<lift>&);
void searchLift(vector<lift>&);
void addVolume(vector<volume>&);

int main(){
    vector<lift> userLifts;
    int userOption;
    
    do{
        printf("1. enter a new lift or 2. to enter an existing lift 3.exit\n>>");
        userOption = userValidation("Enter a number 1 to 3",1,3);
        switch (userOption){
            case 1: addLift(userLifts);
            break;
            case 2: searchLift(userLifts);
            break;
        }
    }while (userOption != 3);
    return 0;
}

void addLift(vector<lift>& userLifts){
    lift newLift; 
    string userLiftName;
    bool exists = false;
        //prompt user for a lift name
    printf("Enter a new lift below\n>>");
    userLiftName = stringValidation("Enter a valid excercise",5,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with
        //search our lift array to make sure that lift doesn't already exist in our database
    for (int count = 0; count < userLifts.size() && (exists == false);count++){
        if (userLiftName == userLifts[count].name){
            printf("The lift %s already exists.\n", userLiftName.c_str());
            exists = true;
        }
    }
    if (exists == false){
        newLift.name = userLiftName;
        userLifts.push_back(newLift);
    }
}

void searchLift(vector<lift>& userLifts){
    string userLiftName;
    bool exists = false;
        //get lift name from user
    printf("Which lift did you do for this session?\n");
    userLiftName = stringValidation("Enter a valid excercise",5,30);
    userLiftName = makeLower(userLiftName); //make the string all lowerCase so it is easier to work with

        //loop through lift vector to find our lift
    for (int count = 0; count < userLifts.size() && (exists == false); count++){
        if (userLiftName == userLifts[count].name){
            exists = true;
            addVolume(userLifts[count].liftVolume);
        }
    }
    if (exists == false)
        printf("Lift not found. Please add a lift");
}

void addVolume(vector<volume>& liftVolume){
    int userOption;
    do{
        printf("Press 1 to enter another set or 2 to exit");
        userOption = userValidation("1 for another set, 2 to exit",1,2);
        if (userOption == 1){
            int userWeight = 0;
            int userReps = 0;
            printf("Enter Weight >> ");
            userWeight = userValidationDisplayBounds("What do you live in the moon?", "Okay, Arnold, the girl at the smithson isn't watching\nEnter a weight",0.0f,900.0f);
        }
    }while (userOption != 2);
}
#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
using namespace std;

    //each lift has a name and volume. Volume is the weight and for how many
    //reps that weight was done. Therefore we have a weight vector that has a parallel 2-d rep vector
    //each row in the reps vector corresponds to a session, each columm is a set that contains reps
struct Lift{
    string name;
    vector<float> weight;
    vector<vector<int>> reps;
};

void addVolume(Lift&);
void addSession(vector<Lift>& userLifts);
int searchLifts(vector<Lift>, string);

int main(){
        //each element in this vector is a different lift, each lift should have only
        //one structure
    vector<Lift> userLifts{2};
        //fill userLifts for testing
    userLifts[0].name = "squat";
    userLifts[1].name = "pull up";
    addSession(userLifts);
}

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

int searchLifts(vector<Lift> userLifts, string liftName){
        //loop through lift vector to find our lift
    for (int count = 0; count < userLifts.size(); count++){
        if (liftName == userLifts[count].name){
            return count;
        }
    }
    return -1; //lift was not found
}
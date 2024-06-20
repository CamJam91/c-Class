#include<iostream>
#include<vector>
#include<string>
#include<inputValidation.h>
#include<stdio.h>
#include<sort.h>
using namespace std;

    //each lift has a name and a 2d vector called voume that represents weight and reps
struct Lift{
    string name;
    vector<float> weight;
    vector<vector<int>> reps;
};
    //prototypes
int searchLifts(vector<Lift>, string);
void displayVolume(vector<Lift>);

int main(){
    vector<Lift> userLifts;
    int userOption;
}

int searchLifts(vector<Lift> userLifts, string liftName){
        //loop through Lift vector to find our Lift
    for (int count = 0; count < userLifts.size(); count++){
        if (liftName == userLifts[count].name){
            return count;
        }
    }
    return -1; //Lift was not found
}

void displayVolume(vector<Lift> userLifts){
    string userLiftName;
    int liftPOS;
    printf("Which lift would you like to display?");
    userLiftName = stringValidation("Enter a valid lift", 5,30);
    liftPOS = searchLifts(userLifts, userLiftName);
    if (liftPOS == -1)
        printf("That lift was not found.\n\n");
    else{
        printf("%s\n",userLifts[liftPOS].name.c_str());
        for (int sessionCount = 0; sessionCount < userLifts[liftPOS].weight.size(); sessionCount++){
            printf("%-20%s\n","Session",sessionCount,": ");
            printf("%s%s\n","Weight",userLifts[liftPOS].weight[sessionCount]);
            for(int repCount = 0;repCount < userLifts[liftPOS].reps[sessionCount].size();repCount++){
                
            }
        }
        printf("%-20s %20s", "Weight", "Reps\n");
        for(int count = 0; count < (userLifts[liftPOS].volume.size()); count++){
            printf("%-20d %20d\n", userLifts[liftPOS].volume[count][count], userLifts[liftPOS].volume[count][count+1]);
        }
    }
}


#include "../include/Lift.h"
#include<vector>
using namespace std;

    //getters
string Lift::getName(){
    return name;
}
int Lift::getSets(){ //returns the number of sets in this lift (weight/reps array size)
    return weights.size();
}
int Lift::getReps(int set){ //return the reps that live at a certain position safeguards against bounds errors
        if (reps.size() >= set){
            return (reps[set]);
        }else{
            throw boundsException(set);
        }
    }
double Lift::getWeight(int set){ //return the weight that lives at a certain position, safeguards against bounds errors
        if (weights.size() >= set){
            return weights.size(); 
        }else{
            throw boundsException(set);
        }
    }

vector<int>* Lift::getRepsList(){ //return a pointer to the reps list
    return &reps;
}
vector<double>* Lift::getWeightList(){ //return a pointer to the weights list
    return &weights;
}

        //setters
            //add a set to this lift (weight and reps parallel vector) a set is a weight done for certain reps, this is used for user input 
void Lift::addSet(int userReps, double userWeight){
    if (userReps < 1 || userReps > 1000){
            throw rangeException(userReps);
        }else if(userWeight < 0 || userWeight > 1000){
            throw rangeException(userWeight);
        }else{
            reps.push_back(userReps);
            weights.push_back(userWeight);
        }
    };
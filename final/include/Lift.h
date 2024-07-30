#ifndef LIFT_H
#define LIFT_H
#include"LiftException.h"
#include <string>
#include<vector>
using namespace std;

    //each instance of the lift class represents a type of lift. This will have 2 parallel vectors that represent weight and the reps at which the weight was done. 
    //each pair of reps/weight elements are a set. 
class Lift{
    private:
        string name;
        vector<double> weights;
        vector<int> reps;
    
    public:
        //constructor
    Lift(string name){ //This is the only constructor
        this->name = name;
    }

        //getters
    string getName();
    int getSets(); //returns the number of sets in this lift (weight/reps array size)
    int getReps(int set); //return the reps that live at a certain position safeguards against bounds errors
    int getWeight(int set); //return the weight that lives at a certain position, safeguards against bounds errors
    vector<int>* getRepsList(); 
    vector<double>* getWeightList(); 

        //setters
            //add a set to this lift (weight and reps parallel vector)
    void addSet(int userReps, double userWeight);
    void addRep(int rep);
    void addWeight(double weight);
    };
#endif
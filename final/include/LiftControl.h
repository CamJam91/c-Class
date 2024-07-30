#ifndef LIFTCONTROL_H
#define LIFTCONTROL_H
#include<vector>
#include"Lift.h"
using namespace std;

class LiftControl{
    private:
        vector<Lift> userLifts;
    public:
        //constructor
        LiftControl(fstream& liftFile);

        //getters
        int getNumberLifts();
        int getLift(string search);

        //setters
        int addLift(string lift);
        int addVolume(string lift, int reps, double weight);

        //file operations
        void pushVolume(fstream& repFile, fstream& weightFile, Lift lift);
        void getVolume(fstream& repFile, fstream& weightFile, Lift lift);
        void pushName(fstream& liftFile, Lift lift);

        //utility functions
        int returnLift(vector<Lift> userLifts, string targetLift);
};


#endif
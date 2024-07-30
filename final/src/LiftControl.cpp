#include"../include/LiftControl.h"
#include"../include/Lift.h"
#include<iostream>
#include<string>
using namespace std;

LiftControl::LiftControl(fstream& liftFile){ //this needs to be created everytime the program is run, all stats are added after
    if(!liftFile.good())
        throw (fileException(liftFile.rdstate()));
    //userLifts calls the lift constructor as many times as the file demands
    string liftName;
    while (liftFile.read(reinterpret_cast<char*>(& liftName), sizeof(string))){
        userLifts.push_back(Lift(liftName));
    }
} //this needs to be created everytime the program is run, all stats are added after

//getters
int LiftControl::getNumberLifts(){
    return userLifts.size();
}
    //if lift exists, return position, else return -1
int LiftControl::getLift(string lift){
    for (int count = 0; count < userLifts.size(); count++){
        if(lift.compare(userLifts[count].getName())){
            return count;
        }
    }
    return -1;
}

    //setters
        //checks if the lift exists using getLift (position == -1), if so push lift vector
int LiftControl::addLift(string lift){
    int position = getLift(lift);
    if (position == -1)
        userLifts.push_back(lift);
    return position;
}

        //calls getLift to figure the position of target lift, it then calls addSet on the lift, then returns the position for validation purposes
int LiftControl::addVolume(string lift, int reps, double weight){
    int position = getLift(lift); //get lift position
    if(position != -1){
        userLifts[position].addSet(reps,weight);
    }
    return position;
}

//file operations
    //checks if file is good for appending and then writes parameter data to file

    //checks if files are good for appending data then writes parameter data to file
void LiftControl::pushVolume(fstream& repFile, fstream& weightFile, Lift lift){
    if (!repFile.good()) //if file flag is not good throw exception
        throw (fileException(repFile.rdstate())); //hand flag parameter to fileException
    if(!weightFile.good())
        throw (fileException(weightFile.rdstate()));
    repFile.write(reinterpret_cast<const char*>(lift.getRepsList()), sizeof(lift.getSets())); //getRepsList() returns pointer, data from pointer is 
        //written to file, size is determined by getSets()
    weightFile.write(reinterpret_cast<const char*>(lift.getWeightList()), sizeof(lift.getSets()));
}
    //checks if files are good for reading data then reads into proper lift array
void LiftControl::getVolume(fstream& repFile, fstream& weightFile, Lift lift){
    if (!repFile.good()) //if file flag is not good throw exception
        throw (fileException(repFile.rdstate())); //hand flag parameter to fileException
    if(!weightFile.good())
        throw (fileException(weightFile.rdstate()));
     int tempRep; //for holding reps
     double tempWeight; //for holding weight
    while(repFile.read(reinterpret_cast<char*>(&tempRep), sizeof(int))){ //read into vector until end of file
        lift.addRep(tempRep); //call addRep member
    }
    while(weightFile.read(reinterpret_cast<char*>(&tempWeight), sizeof(int))){
        lift.addWeight(tempWeight);
    }
}

//utility function
int returnLift(vector<Lift> userLifts, string targetLift){
   //loop through Lift vector to find our Lift
    for (int count = 0; count < userLifts.size(); count++){
        if (targetLift == userLifts[count].getName()){
            return count;
        }
    }
    return -1; //Lift was not found 
}

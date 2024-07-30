#include<iostream>
#include<fstream>
#include"../include/Lift.h"
#include"../include/LiftControl.h"
#include"../include/LiftException.h"
#include<string>
using namespace std;

int main(){
    fstream  testFile;
    testFile.open("testFile.dat", ios::out | ios::binary | ios::app);
    if (testFile.fail()){
        testFile.open("testFile.dat", ios::out | ios::binary | ios::app);
    }
    LiftControl testControl;
    string testName = "Squat";

    int addLiftTest = testControl.addLift(testName); //add our test to userLifts vector
    int addVolumeTest = testControl.addVolume(testName, 10, 100);

        //put data into binary file
    testControl.pushData();

    return 0;
}
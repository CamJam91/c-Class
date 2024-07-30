#include "../include/Lift.h"
#include "../include/LiftControl.h"
#include "../include/LiftException.h"
#include<string>
using namespace std;

int main(){
    LiftControl testControl;
    string testName = "Squat";

    int addLiftTest = testControl.addLift(testName); //add our test to userLifts vector
    printf("Add lift test: %d\n", addLiftTest);
    int getLiftTest =  testControl.getLift(testName);
    printf("getLiftTest: %d\n",getLiftTest);

    int getNumberLiftsTest = testControl.getNumberLifts();
    printf("getNumberLiftsTest: %d\n", getNumberLiftsTest);

    return 0;
}
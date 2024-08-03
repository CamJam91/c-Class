#include "../include/Lift.h"
#include "../include/LiftControl.h"
#include "../include/LiftException.h"
#include "../include/inputValidation.h"
#include <string>
using namespace std;

LiftControl testControl();
void newLift();
int main(){
    int userOption = 0; 
    do{
        printf("1.Enter a Lift \n2.Enter a Session \n3.Exit\n>>");
        userOption = userValidation("Enter a valid Menu option/n>>", 1, 3);
        switch(userOption){
            case 1: newLift();
            break;
        }
    }while(userOption!=3);
    
    return 0;
}

void newLift(){
    printf("Which lift would you like to add?");
    string liftName = stringValidation("Enter a valid lift please", 3, 30);
    LiftControl::createFile(liftName);
}
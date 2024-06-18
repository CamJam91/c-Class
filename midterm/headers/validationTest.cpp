#include<iostream>
#include<string>
using namespace std;

string dateValidation(string errorDisplay, string format);

int main(){

}

string dateValidation(string errorDisplay){
        string userDate;
        bool formatOk = false;
        cin.clear();
        cin.ignore();
        while (!(getline(cin, userDate)) || !formatOk){
                char slashOne = userDate[2];
                char slashTwo = userDate[5];
                char numbers[8] = {userDate[0],userDate[1],userDate[3], userDate[4], userDate[6], userDate[7], userDate[8], userDate[9]};

                if (userDate.length()!= 10)
                        break;
                else if ((slashOne != '/') || (slashTwo != '/'))
                        break;
                else if ()
                }
}
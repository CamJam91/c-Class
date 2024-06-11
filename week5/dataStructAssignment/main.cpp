#include<iostream>
#include<string>
#include<vector>
#include<inputValidation.h>
#include<iomanip>
using namespace std;

    //nested structure that is used in Team
struct WinLoss{
    int wins;
    int losses;
};

struct Team{
    WinLoss total;
    WinLoss home;
    WinLoss away;
    string name;
};

vector<Team> teams;

    //prototypes
Team getTeam();
WinLoss getWinLoss(string homeOrAway);
int menu();
void displayTeam(Team);
void displayWinLoss(WinLoss);
void displayTeam(Team);
void displayAllTeams(vector<Team>);
void findTeam(vector<Team>);

int main(){
    int userOption = 0;
    do{
        userOption = menu();
        switch (userOption){
            case 1: teams.push_back(getTeam());
                break;
            case 2: displayAllTeams(teams);
                break;
            case 3: findTeam(teams);
        }
    }while (userOption !=4);
    return 0;
}

int menu(){
    int userOption = 0;
    cout << "Choose an option: " << endl;
    cout << "1.Enter a new team\n2.Display all teams\n3.Display a particular team\n4.exit\n";
    userOption = userValidation("Please Enter a valid option 1 -4\n",1,4);
    return userOption;
}

    //prompt and receive cin from user for team.name, then add records for home and away members,
    //respectively using the getWinLoss, then total all wins and all losses and save in 
    //totalstructure, WinLoss, lastly return this new Team 
Team getTeam(){
    Team newTeam;
    cout << "Enter a  new team name: ";
    newTeam.name = stringValidation("Please eneter a valid team name", 5, 35);
    newTeam.home = getWinLoss("Home");
    newTeam.away = getWinLoss("away");
    newTeam.total.wins = (newTeam.home.wins + newTeam.away.wins);
    newTeam.total.losses = (newTeam.home.losses + newTeam.away.losses); 

    return newTeam;
}

    //create a WinLoss ADT, use string for proper prompt from user, this is used in getTeam
    //to get thte wins and losses for either home or away after user validation
WinLoss getWinLoss(string homeOrAway){
    int wins,
    losses;
    WinLoss newRecord;
    cout << "Enter the number of " << homeOrAway << " wins: " <<endl;
    wins = userValidation("Enter a valid number of wins", 0, 81);
    cout << "Enter the number of " << homeOrAway << " losses: " <<endl;
    losses = userValidation("Enter a valid number of losses", 0, 81);
    newRecord.wins = wins;
    newRecord.losses = losses;
    return newRecord;
}

//simple display function, will take a WinLoss adt, namely one that is nested inside a team structure
void displayWinLoss(WinLoss record){
    cout << record.wins << "-" << record.losses;
}

void displayTeam(Team team){
    cout << "\nTeam: " << team.name << endl;
    cout << "\nTotal W/L: ";
    displayWinLoss(team.total);
    cout << "\nHome W/L: ";
    displayWinLoss(team.home);
    cout << "\nAway W/L: ";
    displayWinLoss(team.away);
    cout << endl << endl;
}

void displayAllTeams(vector<Team> team){
    for (int count = 0; count < team.size();count++){
        displayTeam(team[count]);
    }
}

void findTeam(vector<Team> teams){
    string userTeam;
    string userCity;

    cout << "Enter a team name to find: " << endl;
    userTeam = stringValidation("Please enter a valid team name", 5, 35);
    userCity = firstWord(userTeam);
    

    int count;
    for (count = 0; count < teams.size(); count++){
        if (userTeam == teams[count].name){
            displayTeam(teams[count]);
            break;
        }else if()
    }
    if (count == teams.size()){
        cout << "Team not found." << endl;
    }
}

firstWord(Team team){

}
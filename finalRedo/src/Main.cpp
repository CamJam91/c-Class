#include "../include/Character.h"
#include "../include/CharacterFileHandler.h"
#include "../include/inputValidation.h"
#include "../include/CharacterHandler.h"
using namespace std;

void createCharacter(vector<Character>&);
void showAll(vector<Character>&);
void showCharacter(vector<Character>&);
void deleteCharacter(vector<Character>&);
void initiateFight(vector<Character>&, Character);
void fightTest(vector<Character>&);

int main(){
    int userOption;
    vector<Character> characterList;
    try{
        CharacterFileHandler::charImport(characterList); //create and or populate character file
    }catch(string exceptionString){
        cout << exceptionString << endl;
    }
    printf("Welcome to your RPG Character tracker\n");
    do{
        printf("1.Create a Character \n2.Search for a Character \n3.Show all Character names \n4.Delete a Character \n5.Fight a Goblin \n6.Exit\n");
        userOption = userValidation("1.Create a Character \n2.Search for a Character \n3.Show all Character names \n4.Delete a Character \n5.Fight a Goblin\n6.Exit\n", 1, 5);
        switch(userOption){
            case 1: createCharacter(characterList);
            break;
            case 2: showCharacter(characterList);
            break;
            case 3: showAll(characterList);
            break;
            case 4: deleteCharacter(characterList);
            break; 
            case 5: fightTest(characterList);
            break;
        }
    }while(userOption != 6);
}

    //asks user if they want to construct charactwe with custom stat args, calls default or arg constructor depending
void createCharacter(vector<Character>& characterList){
    printf("Would you like to create a custom character? Y|N\n>>");
    char userChoice = userValidation("Y | N\n>>",'Y','N');
    if (userChoice == 'Y'){ //create custom
        printf("Enter a name for your character\n>>");
        string newChar = stringValidation("Enter a valid character name\n>>", 3, 40);
        int stat[Character::getStatSize()]; //create stat array that is same as Character.STATSIZE
        int statNum;
            //get stat numbers from user
        for (int count = 0; count < Character::getStatSize();count++){
            printf("%s: ", Character::getStatName(count)); //get stat name
            statNum = userValidation("Enter A valid starting stat number 1-10",1,10);
            stat[count] = statNum;
        }
        try{CharacterHandler::createCharacter(newChar.c_str(),stat, characterList);
        }catch(string characterException){
            printf("%s\n", characterException);
        }
    }else{ //default constructor
        printf("Enter a name for your character\n>>");
        string newChar = stringValidation("Enter a valid character name\n>>", 3, 40);
        try{ 
            CharacterHandler::createCharacter(newChar.c_str(), characterList);
        }catch(string characterException){
            printf("%s\n", characterException);
            }
    }
}

    //checks for character in characterList array by callingn charSearch, calls showInfo or returns not found prompt
void showCharacter(vector<Character>& characterList){
   printf("Which Character would you like to view?\n>>");
   string targetCharacter = stringValidation("Please enter a valid character name\n>>", 3, 40);
   int position = CharacterHandler::charSearch(targetCharacter.c_str(), characterList);
   if (position == -1)
    printf("Character not found");
   else
    CharacterHandler::showInfo(characterList[position]);
   printf("\n");
}

    //loops through the character array and calls .getName to show their names
void showAll(vector<Character>& characterList){
    if (characterList.size()==0)
        printf("You have no saved characters\n");
    else{
        printf("Saved Characters:\n");
        for (int count = 0; count < characterList.size(); count++){
            printf("%s\n",characterList[count].getName());
            }
    }
}

    //get user input for which character needs deleting, then after validating its existence, call charDelete to recreate file, then clear and 
    //repopulate characterList
void deleteCharacter(vector<Character>& characterList){
    printf("Which Character would you like to delete?");
    string deleteChar = stringValidation("Enter a valid character name", 3, 40);
    int position = CharacterHandler::charSearch(deleteChar.c_str(), characterList);
    if (position == -1)
        printf("Character not found");
    else{ //character exists, call charDelete on it
        try{CharacterFileHandler::charDelete(characterList, position);
        characterList.clear();
        }catch(string fileException){
            printf("%s\n", fileException.c_str());
        } //after character is deleted, character file is altered and needs to be recreated
        try{CharacterFileHandler::charImport(characterList);
        }catch(string fileException){
            printf("%s\n", fileException.c_str());
        }
    }
}

    //takes use input and calls fight function with valid Character, handles outcome by calling stat increase or negative prompt
    //
void initiateFight(vector<Character>& characterList, Character enemy){
    string fightCharacter;
    printf("Which character will fight?\n>>");
    fightCharacter = stringValidation("Enter a valid Character name", 3,40);
    int position = CharacterHandler::charSearch(fightCharacter.c_str(), characterList);
    if (position == -1)
        printf("Character not found");
    else{ //if character exists call fight function
        printf("%s fights %s!\n", characterList[position].getName(),enemy.getName());
        int winner = CharacterHandler::fight(characterList[position], enemy);
        if(winner == 0){ //character wins, desired stat needs to be increased with increaseStat call
            int statIncrease;
            printf("%s Wins!\n", characterList[position].getName());
            printf("Which stat would you like to level?\n");
            for (int count = 0; count < Character::getStatSize(); count++){
                printf("%d for %s\n", count + 1, Character::getStatName(count));
            }
            statIncrease = userValidation("Enter a valid number",1,6);
            characterList[position].increaseStat(statIncrease-1);
        }else{
            printf("%s lost!", characterList[position]);
        }
    }
}

    //used for easy enemy creation to test how the fight functino works, separates user input and leveling with enemy stats
void fightTest(vector<Character>& characterList){
    int enemyStats[] = {4,3,1,1,2,1};
    string enemyName = "a Goblin";
    Character Goblin = Character(enemyName.c_str(), enemyStats);
    initiateFight(characterList, Goblin);
}
//Cameron Murphy
//CIS1202
//8-4-2024
#include "../include/CharacterHandler.h"
#include "../include/Character.h"
#include "../include/CharacterFileHandler.h"
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

    //checks pass Character vector to check if Character already exists, if it does, throw exception, else
    //pushg array and append to binary file
void CharacterHandler::createCharacter(const char* newChar, vector<Character>& characterList){
        //check if this character already exists, if it does new character is not created
    if (charSearch(newChar, characterList) != -1){
        string characterException = "That character already exists, delete this character to recreate a new one with the same name\n";
        throw characterException;
    }else{
        Character NewCharacter(newChar);
        characterList.push_back(NewCharacter);//add character to our array
        CharacterFileHandler::charSave(NewCharacter);
    }
}
    //overloaded createCharacter function for custom character creation
void CharacterHandler::createCharacter(const char* newChar, int stats[], vector<Character>& characterList){
    //check if this character already exists, if it does new character is not created
    if (charSearch(newChar, characterList) != -1){
        string characterException = "That character already exists, delete this character to recreate a new one with the same name\n";
        throw characterException;
    }else{
        Character NewCharacter(newChar);
        for (int count = 0; count < Character::getStatSize();count++){
            try{
                NewCharacter.setStat(count, stats[count]);
            }catch(string CharacterError){
                throw CharacterError; //rethrow error
            }
        }
        characterList.push_back(NewCharacter);//add character to our array
        CharacterFileHandler::charSave(NewCharacter);
    }
}


    //takes a param and a vector of characters, search list for characters, and return position on find or
    //illegal -1 position on not found
int CharacterHandler::charSearch(const char* targetCharacter, vector<Character>& characterList){
  bool found = false;
  int position = -1;
  for (int count = 0; count < characterList.size() && found == false; count++){
    if (strncmp(targetCharacter, characterList[count].getName(),41) == 0){
        position = count;
        found = true;
    }
  }
  return position;
}

    //prints character name and each stat associated with that character, statName is a static value of strings in 
    //Character and stat is individual to that character
void CharacterHandler::showInfo(Character showChar){
    printf("%s\n", showChar.getName());
    for (int count = 0; count < Character::getStatSize(); count++){
        printf("%s: %d\n", showChar.getStatName(count), showChar.getStat(count));
    }
}

    //takes in twop character, uses fmod to figure float of constitution divided by strength. Returns 0 for friendly
    //win (higher health) and 1 for enemy win
int CharacterHandler::fight(Character friendly, Character enemy){
        //use fmod to dicide constitution by strength and get float remainder
    double friendlyHealth = fmod(friendly.getStat(2), enemy.getStat(0));
    double enemyHealth = fmod(enemy.getStat(2), friendly.getStat(0));
    if (friendlyHealth >= enemyHealth) //Character has won
        return 0;
    else
        return 1; //enemy has won
}
#include "../include/Character.h"
#include <string>
using namespace std;

    //for user viewing of stat names
const static char statNames[6][20] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};

   //getters
const char* Character::getName(){
    return character.name; 
}
int Character::getStat(int statCount){
    return character.stats[statCount];
}
int Character::getStatSize(){
    return STATSIZE;
}
const char* Character::getStatName(int stat){
    return statNames[stat];
}

    //setters
void Character::setName(const char* name){
    name = name;
}
void Character::setStat(int statCount, int statNum){
    if(statNum < 0){ //throw error on illegal stat num
        string CharacterError = "A negative stat is not allowed\n";
    }else{
        character.stats[statCount] = statNum;
    }
}
void Character::increaseStat(int statCount){
    character.stats[statCount]++;
}


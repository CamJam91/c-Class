//Cameron Murphy
//CIS 1202
//8-4-2024
//Character class holds character name and stat data as well as simple setters and getters

#ifndef Character_H
#define Character_H

#include <string>
#include <cstring>
using namespace std;


class Character{
    protected:
        const static int STATSIZE = 6; //size of our stats
            //CharacterInfo holds the actual data fields of a Character instance, character is initialized every time
        struct CharcterInfo{
            char name[40];
            int stats[STATSIZE] = {5,5,5,5,5,5}; //default stats
            }character;
    
    public:
        //constructors
            //default stat constructor
        Character(const char* name){
            strcpy(character.name, name); //copy parameter name
        }
            //arg constructor
        Character(const char* name, int stats[]){
            strcpy(character.name, name);
            for (int count = 0; count < STATSIZE; count++){ //each element in stats param is copied to this.stats
                character.stats[count] = stats[count];
            }
        }

            //getters
        const char* getName();
        int getStat(int statCount);
        static const char* getStatName(int stat);
        static int getStatSize();

            //setters
        void setName(const char* name);
        void setStat(int statCount, int statNum);
        void increaseStat(int statCount);
};
#endif
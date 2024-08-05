//Cameron Murphy
//CIS1202
//8-4-2024
//CharacterHandler is a derivesd class of Character and is used to handle interactive character creation and manipulation
#ifndef CHARACTERHANDLER_H
#define CHARACTERHANDLER_H
#include "Character.h"
#include<vector>
using namespace std;

class CharacterHandler : public Character{
    public:
        static void createCharacter(const char*, vector<Character>&);
        static void createCharacter(const char*, int stats[], vector<Character>&);//overload for custom creation
        static int charSearch(const char*, vector<Character>&);
        static void showInfo(Character);
        static int fight(Character, Character);
};
#endif
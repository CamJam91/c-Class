//Cameron Murphy
//CIS1202
//8-4-2024
//File handler is a derived class of Character, it holds a character list and uses this to manipulate file data for Characters
#ifndef CHARACTERFILEHANDLER_H
#define CHARACTERFILEHANDLER_H
#include"Character.h"
#include<vector>
using namespace std;

class CharacterFileHandler : public Character{
    private:
        vector<Character> characterList; //list of user characters
    public:
        //File operations 
        static void charSave(Character);
        static void charImport(vector<Character>&);
        static void charDelete(vector<Character>&, int);
};
#endif
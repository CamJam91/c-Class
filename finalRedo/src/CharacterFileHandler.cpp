//Cameron Murphy
//CIS 1202
//8-4-24

#include "../include/CharacterFileHandler.h"
#include "../include/Character.h"
#include<vector>
#include<fstream>
using namespace std;

    //open binary file for appending character data
void CharacterFileHandler::charSave(Character saveThis){
    fstream characterFile;
    characterFile.open("characters.dat", ios::out | ios::binary | ios::app);
    characterFile.write(reinterpret_cast<char *>(&saveThis), sizeof(Character));
    characterFile.close();
}

    //takes in character list and position of target delete character, opens file in trunc(throw on fail), then
    //resaves file - target delete character 
void CharacterFileHandler::charDelete(vector<Character>& characterList, int position){
    fstream characterFile;
    characterFile.open("characters.dat", ios::out | ios::binary | ios:: trunc); //delete the old file
    if (characterFile.fail()){ //throw exception if file is not able to be opened/created
        string fileException = "Problem creating character file.";
        throw fileException;
    }else{
        for (int count = 0; count < characterList.size();count++){ 
            if (count != position) //ensure that the deleted item is not copied
                characterFile.write(reinterpret_cast<char *>(&characterList[count]), sizeof(Character));
                }
                characterFile.close();
            }
}

    //import our character structures to the character file, on exception file is created and no imports are done
void CharacterFileHandler::charImport(vector<Character>& characterList){
    fstream characterFile;
    characterFile.open("characters.dat", ios::in | ios::binary); //open file for input
    if (characterFile.fail()){ //if there is a problem getting the character file
        string fileException = "!Character file is missing, attempting to create file";
        characterFile.open("characters.dat", ios::out | ios::binary); //create file
        characterFile.close();
        throw fileException;
    }else{
        Character tempChar(""); //create tempChar with a dummy name
        while (characterFile.read(reinterpret_cast<char *>(&tempChar), sizeof(Character))){//ensure we are not at the end of the file
            characterList.push_back(tempChar);
        } 
        characterFile.close();
    }
}

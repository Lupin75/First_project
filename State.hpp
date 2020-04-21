#pragma once
//-----------------INBUILD HEADER FILES----------------------
#include<iostream>
#include<fstream>
//-----------------------------------------------------------
//-----------------USER DEFINED HEADERS----------------------
#include "File.hpp"
//-----------------------------------------------------------
using namespace std;
class State{
/*
       state class is for handling whether which condition the player chooses
        ->if the player chooses '1'  this state is called 'newGame' state thus clearing all the game savaData made before ,if any
        ->if the player chooses '2' this state is called 'continue ' state thus reading the saveData for the player to continue.
        ->if the player chooses '3' this is exit state. 
*/
private:
    File prologue;//for file handling

//-------------------this function is to change a string to lower case----------------
    string toSmall(string large){
        for(int i=0 ; i<large.size() ; i++){
            if(isalpha(large[i])!=0){
                switch(large[i]){
                    case 'A':
                        large[i]='a';
                        break;
                    case 'B':
                        large[i]='b';
                        break;
                    case 'C':
                        large[i]='c';
                        break;
                    case 'D':
                        large[i]='d';
                        break;
                    case 'E':
                        large[i]='e';
                        break;
                    case 'F':
                        large[i]='f';
                        break;
                    case 'G':
                        large[i]='g';
                        break;
                    case 'H':
                        large[i]='h';
                        break;
                    case 'I':
                        large[i]='i';
                        break;
                    case 'J':
                        large[i]='j';
                        break;
                    case 'K':
                        large[i]='k';
                        break;
                    case 'L':
                        large[i]='l';
                        break;
                    case 'M':
                        large[i]='m';
                        break;
                    case 'N':
                        large[i]='n';
                        break;
                    case 'O':
                        large[i]='o';
                        break;
                    case 'P':
                        large[i]='p';
                        break;
                    case 'Q':
                        large[i]='q';
                        break;
                    case 'R':
                        large[i]='r';
                        break;
                    case 'S':
                        large[i]='s';
                        break;
                    case 'T':
                        large[i]='t';
                        break;
                    case 'U':
                        large[i]='u';
                        break;
                    case 'V':
                        large[i]='v';
                        break;
                    case 'W':
                        large[i]='w';
                        break;
                    case 'X':
                        large[i]='x';
                        break;
                    case 'Y':
                        large[i]='y';
                        break;
                    case 'Z':
                        large[i]='z';
                        break;
                    default:
                        large[i]=large[i];
                        break;
                }
            }
        }
        return large;
    }
//-----------------------------------------------------------------------------------------
public:
    string gameState="NULL";           //this is the current state of the game which is defaulted to NULL
    void checkGameState(){
        if(this->toSmall(gameState)=="1"|| this->toSmall(gameState)=="start"||this->toSmall(gameState)=="1."){
            remove("saveFile.txt");
            prologue.prologueEntry();
        }
        else if(this->toSmall(gameState)=="2"|| this->toSmall(gameState)=="continue"||this->toSmall(gameState)=="2."){

        }else if(this->toSmall(gameState)=="3"|| this->toSmall(gameState)=="exit"||this->toSmall(gameState)=="3."){
            cout<<"thanks for playing"<<endl;
            Sleep(1000);//puts the console on hold
            system("exit");//closes the console
        }else{
            cerr<<"incorrect state specified"<<endl;//incorrect gameState specified
            cout<<"please try again"<<endl;
            cin>>gameState;
            this->checkGameState();//recalling the whole process again
        }
    }
};
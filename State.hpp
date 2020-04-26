#pragma once
//-----------------INBUILD HEADER FILES----------------------
#include<iostream>
#include<fstream>
//-----------------------------------------------------------
//-----------------USER DEFINED HEADERS----------------------
#include "File.hpp"
#include"global.hpp"
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
public:
    string gameState="NULL";           //this is the current state of the game which is defaulted to NULL
    void checkGameState(){
        if(toSmall(gameState)=="1"|| toSmall(gameState)=="start"||toSmall(gameState)=="1."){
            remove("saveFile.txt");
            prologue.prologueEntry();
        }
        else if(toSmall(gameState)=="2"|| toSmall(gameState)=="continue"||toSmall(gameState)=="2."){

        }else if(toSmall(gameState)=="3"|| toSmall(gameState)=="exit"||toSmall(gameState)=="3."){

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
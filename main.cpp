/*
Modified by: ABISHEK.R
Last Modified:25-04-2020
Modification details: Created a global header and added code for player details and performing comabt in game header.
TO DO: 
    1, Add a story script
    2, Add Animation
    3, Add Backgroubd Music
    4, Bug fixes
    5, File Handling to enable continue option 
*/ 
//--------------------INBUILD HEADERS--------------------------------------
#include<iostream>
#include<Windows.h>
//-------------------------------------------------------------------------
//---------------------USER DEFINED HEADERS---------------------------------
#include "game.hpp"
#include "Menu.hpp"
#include "State.hpp"
//--------------------------------------------------------------------------
using namespace std;
int main(){
    totalHealth=health;
    maxHealth=totalHealth;
    system("cls");
    Game game;       
    Menu title;       //creating an object called title from class Menu
    title.printTitle();      //printing title screen 
    State status;  //creating an object called game from class State
    cin>>status.gameState;
    status.checkGameState();
}
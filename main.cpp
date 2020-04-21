//--------------------INBUILD HEADERS--------------------------------------
#include<iostream>
//-------------------------------------------------------------------------
//---------------------USER DEFINED HEADERS---------------------------------
#include "Menu.hpp"
#include "State.hpp"
//-------------------------------------------------------------------------
using namespace std;
int main(){
    Menu title;       //creating an object called title from class Menu
    title.printTitle();      //printing title screen
    State game;  //creating an object called game from class State
    cin>>game.gameState;
    game.checkGameState();
}

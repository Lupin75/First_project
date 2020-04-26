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
//--------------------------------------------------------------------------

using namespace std;
int main(){
    totalHealth=health;
    maxHealth=totalHealth;
    system("cls");
    Game game;       //creating an object called title from class Menu
    game.printTitle();     //printing title screen
    x:
    if(input==1){
        system("cls");
        cout<<"Creating character.\n";
        Sleep(200);
        system("cls");
        cout<<"Creating character..\n";
        Sleep(200);
        system("cls");
        cout<<"Creating character...\n";
        Sleep(200);
        system("cls");
        cout<<"Creating character....\n";
        Sleep(200);
        system("cls");
        cout<<"Creating character.....\n";
        Sleep(200);


    //Write the story plot for this game

    
         game.HUD();
    }
    else if(input==2)
        
        /*___________________________________________________________________________________________________________
          code to save the state of the game in a file
        _____________________________________________________________________________________________________________
        */
       cout<<"Sorry!!       This feature is not availabe for now!!";
    else if(input==3)
        exit(0);
    else
    {
        cout<<"Invalid input\n";
        cout<<"Please try again!\n";
        cin>>input;
        goto x;
    }
    
}

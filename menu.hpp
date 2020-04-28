#pragma once
//-----------------------------------------------------------------------------------------------------------------
//inbuild header files
#include<iostream>
#include <fstream>
#include <string>
#include<Windows.h>
//------------------------------------------------------------------------------------------------------------------
using namespace std;
class Menu{
    public:
    //                this class just prints a title name and other options like start,continue,exit
    //                TODO : this class can also play background music for the title screen
    void printTitle(){
      system("cls");
      cout << "\t\t\t\t1 : START"<<endl<<endl<<endl;
      //Sleep(int milliseconds)   --this function puts the console on hold for the given time in milliseconds   --needs to include windows.h
      Sleep(500);
      cout<<"\t\t\t\t2 : CONTINUE"<<endl<<endl<<endl;
      Sleep(500);
      cout<<"\t\t\t\t3 : EXIT"<<endl;
    }
};
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
      cout << R"(
                                            _                   
           _ __   __ _ _ __ ___   ___      | |__   ___ _ __ ___ 
          | '_ \ / _` | '_ ` _ \ / _ \     | '_ \ / _ \ '__/ _ \
          | | | | (_| | | | | | |  __/     | | | |  __/ | |  __/
          |_| |_|\__,_|_| |_| |_|\___|     |_| |_|\___|_|  \___|
                                                  

    )"<<endl;
    //Sleep(int milliseconds)   --this function puts the console on hold for the given time in milliseconds   --needs to include windows.h
    Sleep(2000);
      cout<<R"(


            _ |                   |                 |   
              |              __|  __|   _` |   __|  __| 
              |            \__ \  |    (   |  |     |   
             _|     _)     ____/ \__| \__,_| _|    \__| 
                                                        

      )"<<endl;
      Sleep(1000);
      cout<<R"(

        ___ \                          |   _)                     
           ) |      __|   _ \   __ \   __|  |  __ \   |   |   _ \ 
          __/      (     (   |  |   |  |    |  |   |  |   |   __/ 
        _____| _) \___| \___/  _|  _| \__| _| _|  _| \__,_| \___| 
                                                                  

      )"<<endl;
      Sleep(1000);
      cout<<R"(

            ___ /                          _)  |   
              _ \               _ \ \ \  /  |  __| 
               ) |              __/  `  <   |  |   
            ____/      _)     \___|  _/\_\ _| \__| 
                                                   

      )"<<endl;
      Sleep(1000);
    }
};
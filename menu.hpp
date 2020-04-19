#pragma once
//-----------------------------------------------------------------------------------------------------------------
//inbuild header files
#include<iostream>
#include <fstream>
#include <string>
//------------------------------------------------------------------------------------------------------------------
using namespace std;
/*class mainMenu{
    private:
    string Lines = "";       //All lines
    public:
    string getFileContents (ifstream &menu){
    if (menu)                      //Check if everything is good
    {
	    while (menu.good ())
	    {
	        string TempLine;                  //Temp line
	        getline(menu , TempLine);        //Get temp line
	        TempLine += "\n";                      //Add newline character
	        Lines += TempLine;                     //Add newline
	    }
	    return Lines;
    }else{                           //Return error
	    return "ERROR File does not exist.";
        }
    }
};
*/
class menu{
    public:
    void printTitle(){
        cout << R"(
                                            _                   
           _ __   __ _ _ __ ___   ___      | |__   ___ _ __ ___ 
          | '_ \ / _` | '_ ` _ \ / _ \     | '_ \ / _ \ '__/ _ \
          | | | | (_| | | | | | |  __/     | | | |  __/ | |  __/
          |_| |_|\__,_|_| |_| |_|\___|     |_| |_|\___|_|  \___|
                                                  

    )"<<endl;
    }
};
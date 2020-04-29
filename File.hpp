#pragma once
//------------------INBUILD-HEADER------------------------------
#include<iostream>
#include<fstream>
#include<Windows.h>
//--------------------------------------------------------------
//------------------USER-DEFINED-HEADER-------------------------

//--------------------------------------------------------------
using namespace std;
class File
{
private:
//these data members are for 'prologueEntry' member function----
    char character;
    fstream fin;
//--------------------------------------------------------------
    void readFileOnly(string fileName, int speed,string skipSleep){
    fin.open(fileName,ios::in);
    while (fin >> noskipws >> this->character){
            cout<<this->character;
            if(skipSleep=="yes"||"skip"){
                Sleep(1000/speed);//default 1 second
            }
        }
        fin.close();
    }
public:
    void prologueEntry(){
        char temp = 'q' ;
        system("cls");
        this->readFileOnly("prologue.txt", 30,"no");
        cout<<endl<<"press 'c' to continue";
        while( temp != 'q'){
            this->readFileOnly("#.txt",0,"yes");
            cin >> temp ;
        }
        cout<<endl;
        system("cls");
        this->readFileOnly("titleScreen.txt",1000,"no");
    }
};
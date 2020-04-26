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
    void readFileOnly(string fileName){
    fin.open(fileName,ios::in);
    while (fin >> noskipws >> this->character){
            cout<<this->character;
            Sleep(100);
        }
        fin.close();
    }
public:
    void prologueEntry(){
        system("cls");
        this->readFileOnly("prologue.txt");
    }
};
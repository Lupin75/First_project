#ifndef _gv_
#define _gv_
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <exception>

#undef max

using namespace std;

// To check if the input is integer type
int getInputAsInt(int number)
{
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input type is wrong.... Please try again\nEnter an integer: ";
        number = getInputAsInt(number);
    }
    return number;
}
//Converts all letters in a string to lower case for comparison

//Function to get the cursor to designated line
fstream &GotoLine(fstream &file, unsigned int num)
{

    file.seekg(ios::beg);

    for (unsigned int i = 0; i < num - 1; ++i)
    {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return file;
}

int tea_talk = 0;
int farmTalk = 0;
int input1;
int counter1 = 0;
int temp1;
string tempName1;
int choice1;
string playerName;
int level = 1;
int HP = 0;
int health = 100;
int totalHealth = 0;
int maxHealth = 0;
int enemyXP = 0;
int enemyHP = 0;
int enemyLevel = 0;
string enemyNames[] = {"Enemy1", "Enemy2", "Enemy3", "Enemy4", "Enemy5", "Enemy6"};
int currentEnemyNum = 5;
string currentEnemyName;
int playerAttack;
int playerDamage;
int enemyAttack;
int heal;
int currentXP = 0;
int baseXP = 83;
int XptoLevel = baseXP;
int minLevel = 1;
int maxLevel = 60;
int SPYBAR = 0;
char house;
int line_count = 0;
string line;
int option;

//-------------------this function is to change a string to lower case----------------
string toSmall(string large)
{
    for (int i = 0; i < large.size(); i++)
    {
        if (isupper(large[i]) != 0)
        {
            large[i]=tolower(large[i]);
        }
    }
    return large;
}
int check_binary(int status)
{
    status = getInputAsInt(status);
    if (status != 1 && status != 2)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2): ";
        cin >> status;
        return check_binary(status);
    }
    else
    {
        //cout << "status: " << status << endl;
        return status;
    }
}

int check_tetra(int option)
{
    if (option != 1 && option != 2 && option != 3 && option != 4)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2/3/4): ";
        cin >> option;
        return check_tetra(option);
    }
    else
    {
        //coption << "status: " << status << endl;
        return option;
    }
}
int check_tri(int option)
{
    if (option != 1 && option != 2 && option != 3)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2/3): ";
        cin >> option;
        return check_tri(option);
    }
    else
    {
        //cout << "status: " << status << endl;
        return option;
    }
}

//-----------------------------------------------------------------------------------------
#endif
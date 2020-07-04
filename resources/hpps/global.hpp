#ifndef _gv_
#define _gv_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <ctype.h>
#include <io.h>
bool FileExists(const std::string &Filename)
{
    return access(Filename.c_str(), 0) == 0;
}
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

string playerName;
int SPYBAR = 0;
int option;

//this function is to change a string to lower case
string toSmall(string large)
{
    for (int i = 0; i < large.size(); i++)
        if (isalpha(large[i]) != 0)
            if (isupper(large[i]) != 0)
                large[i] = tolower(large[i]);
    return large;
}
//This function checks for binary int type input 0 or 1. It can also handle other type of inputs
int check_binary(int status)
{
    status = getInputAsInt(status);
    if (status != 1 && status != 2)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2): ";
        //cin >> status;
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
int check_two(int option)
{
    if (option != 1 && option != 2)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2): ";
        cin >> option;
        return check_two(option);
    }
    else
    {
        //cout << "status: " << status << endl;
        return option;
    }
}
int check_penta(int option)
{
    if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2/3/4/5): ";
        cin >> option;
        return check_penta(option);
    }
    else
    {
        //coption << "status: " << status << endl;
        return option;
    }
}

 //This function helps us conttrol the speed of output using "speed" var
void displaySlow(string line, int speed = 100000, bool sleepStats = true)
{
    // char ch;
    for (int i = 0; i < line.size(); i++)
    {
        cout << line[i];
        if (sleepStats == true)
            sf::sleep(sf::milliseconds(1000 / speed));
    }
    cout << "\n";
}

//Wraps text to avoid cutting of words in terminal
void wrap(string text, size_t line_length = 110)
{
    std::istringstream words(text);
    std::ostringstream wrapped;
    std::string word;

    if (words >> word)
    {
        wrapped << word;
        size_t space_left = line_length - word.length();
        while (words >> word)
        {
            if (space_left < word.length() + 1)
            {
                wrapped << '\n'
                        << word;
                space_left = line_length - word.length();
            }
            else
            {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    displaySlow(wrapped.str());
}

//-----------------------------------------------------------------------------------------
#endif
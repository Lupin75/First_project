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

bool FileExists(const std::string &Filename)
{
    std::ifstream file;
    file.open(Filename);
    if(file.fail()){
        file.close();
        return false;
    }else{
        file.close();
        return true;
    }
}

using namespace std;

//This function returns the OS name
string findOs()
 {
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif __linux__
    return "Linux";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
 }

//This function clears and pauses the terminal
    void cls()
    {
        
        string osName = findOs();
        if(osName == "Windows 32-bit")
        {
            system("pause");
            system("cls");
        }
        else
        {
            cout<<"Press any key to continue...";
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            system("clear");
        }
    }
    
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
    option = getInputAsInt(option);
    if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
    {
        cout << "Error...No such option available" << endl
             << "Enter option (1/2/3/4/5): ";
        //cin >> option;
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

class Bar
{
private:
    int amountOfFiller,
        pBarLength = 50,
        currUpdateVal = 0;
    double currentProgress = 0,
           neededProgress = 100;
    string firstPartOfpBar = "[",
           lastPartOfpBar = "]",
           pBarFiller = "|",
           pBarUpdater = "/-\\|";

public:
    void update(double newProgress)
    {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress) * (double)pBarLength);
    }
    void print()
    {
        currUpdateVal %= pBarUpdater.length();
        cout << "\r"             //Bring cursor to start of line
             << firstPartOfpBar; //Print out first part of pBar
        for (int a = 0; a < amountOfFiller; a++)
        { //Print out current progress
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++)
        { //Print out spaces
            cout << " ";
        }
        cout << lastPartOfpBar                                                  //Print out last part of progress bar
             << " (" << (int)(100 * (currentProgress / neededProgress)) << "%)" //This just prints out the percent
             << flush;
        currUpdateVal += 1;
    }

    void progressBar(int progress, int sleepRate=1)
    {
        cout<<"\nProgress\n";
        update(progress); //How much new progress was added (only needed when new progress was added)
        //Print pBar:
        print();
        currentProgress = 0;
        cout<<endl;
    }
    void loadBar(int sleepRate = 1)
    {
        for (int i = 0; i < 100; i++)
        {
            update(1); //How much new progress was added (only needed when new progress was added)
            //Print pBar:
            print();
            sf::sleep(sf::milliseconds(sleepRate));
        }
        currentProgress = 0;
    }
};
//-----------------------------------------------------------------------------------------
#endif
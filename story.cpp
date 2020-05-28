#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "global.hpp"
/*
    Author      : Nirmal Kumar
    Created on  : 21 05, 2020
    Filename    : &TM_FILENAME
    Description : 
*/
/* Modified:
 Name: Abishek.R
 Created on : 28-05-2020
 Description: Improved
 */
using namespace std;
void cls()
{
    system("pause");
    system("cls");
}
void displaySlow(string line, int speed = 30, bool sleepStats = true)
{
    char ch;
    for (int i = 0; i < line.size(); i++)
    {
        cout << line[i];
        if (sleepStats == true)
            Sleep(1000 / speed);
    }
    cout << "\n";
}

int main()
{
    /*string p_name;
    cout<<"Enter a name for your character: ";
    cin>>p_name;
    
    //birds chirping or somekind of a morning sound
    //Sleep(2000);
    cout<<"    You just woke up from a comfortable sleep. You sit up on the heavenly mattress and look outside your bedside window to find the Sun rising above the horizon. You get up from the bed and scan your room the King of Jawad provided you, in the most luxurious mansion in the kingdom. You find the brown bag of 1000 gold coins and the note from the King of Jawad that reads:\n"
	<<"        We are deeply honoured to have you Detective "<<p_name<<", the Greatest Detective in all kingdoms to participate in our annual festival. Enjoy your stay.\n"
    <<"Annual festival: The richest festival of all kingdoms which goes on for a month. Anyone from any kingdom can come, participate and enjoy. You were one of the chief guests for their inaugural function which held last week.\n";
    system("pause");
    
    //door knocking sound
    cout<<"    As you walk towards the balcony, you hear a sudden knocking on the door. You rush to the door and open to find nobody in the corridor. When you look down, you find a white cover. You open the cover to find a letter with the following words.\n"
    <<"        An important person is missing. We need your help. Come quickly to Jade City and don’t tell anyone.\n                                -King George"
    <<"\nDo you accept the invitation?\n"
    <<"    1: Yes-> Welcome to the game\n"
    <<"    2: No-> Close the game\n"
    <<"Enter 1 or 2\n";

    int status;
    cin>>status;

    if (status==1)
    {
        
    }
    else if(status == 2)
    {
        "Ending game .. Thank you";
    }
    else
    {
        cout<<"Choose:\n    (1) : To start the game\n    (2) : To exit the game\n";
    }*/
    std::vector<string> story_line;
    fstream story;
    string line;
    string bold;
    story.open("story.txt");
    int line_count = 0;
    while (line_count < 3)
    {
        line.clear();
        getline(story, line, '\n');
        story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    //line_count=0;
    cout << endl;
    cls();
    //cout<<"    ";
    while (line_count < 10)
    {
        line.clear();
        getline(story, line, '\n');
        story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    //cout<<"linefawk"<<line_count;
    int status;
    cin >> status;

    if (status == 1)
    {
        while (line_count < 27)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            if (line_count == 13)
            {
                line = line + " " + playerName;
                displaySlow(line);
            }
            else
                displaySlow(line);
            line_count++;
        }
        int option;
        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        while (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
        {
            cin >> option;
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, 28);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f1++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 2)
            {
                if (f2 == 0)
                {
                    GotoLine(story, 30);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f2++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 3)
            {
                if (f3 == 0)
                {
                    GotoLine(story, 32);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f3++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 4)
            {
                if (f4 == 0)
                {
                    GotoLine(story, 34);
                    int ln = 0;
                    while (ln < 7)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f4++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            cout << endl;

            if (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
            {
                for (int i = 22; i < 26; i++)
                    displaySlow(story_line[i]);
            }
        }
        cls();
        line_count = 41;
        GotoLine(story, 42);
        while (line_count < 48)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        cls();
        line_count = 49;
        GotoLine(story, 50);
        while (line_count < 57)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        //int option;
        f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        while (f2 == 0)
        {
            cin >> option;
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, 59);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f1++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 2)
            {
                if (f2 == 0)
                {
                    GotoLine(story, 61);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f2++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 3)
            {
                if (f3 == 0)
                {
                    GotoLine(story, 63);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f3++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            cout << endl;

            if (f2 == 0)
            {
                GotoLine(story, 54);
                int ln = 0;
                while (ln < 4)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
            }
        }
        // my code
        cls();
        line_count=65;
        GotoLine(story,66);
        while (line_count < 73)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        cls();
        GotoLine(story,75);
        while (line_count < 88)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        
       /* 
        cls();
        line_count = 90;
        GotoLine(story,91);
        while (line_count < 98)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        line_count = 99;
        GotoLine(story,100);
        while (line_count < 122)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        cls();
        line_count=125,
        GotoLine(story,126);
        */
    }

    else if (status == 2)
    {
        cout << "You should accept the invitation to play the game!" << endl;
        cout << "Ending game...Thank You" << endl;
        exit(0);
    }
    else
    {
        cout << "Choose:\n    (1) : To start the game\n    (2) : To exit the game\n";
    }
    return 0;
}

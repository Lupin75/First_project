#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "global.hpp"
/*
    Last modified by: Nirmal Kumar
    Created on      : 21 05, 2020
    Last modified   : 10/6/2020 1:40 AM
    Filename        : &TM_FILENAME
    Description     : 
*/

using namespace std;
void cls()
{
    system("pause");
    system("cls");
}

void displaySlow(string line, int speed = 10000, bool sleepStats = true)
{
    // char ch;
    for (int i = 0; i < line.size(); i++)
    {
        cout << line[i];
        if (sleepStats == true)
            Sleep(1000 / speed);
    }
    cout << "\n";
}
void pod_conv(int line_n, int choices)
{
    fstream story;
    story.open("custom.txt");
    GotoLine(story, line_n);

    int option;
    if (choices == 4)
    {
        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        while (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
        {
            option = check_tetra(getInputAsInt(option));
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, line_n);
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
                    GotoLine(story, line_n + 2);
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
                    GotoLine(story, line_n + 4);
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
                    GotoLine(story, line_n + 6);
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
            else
            {
                cout << "No such option is present" << endl;
            }
            cout << endl;

            if (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
            {
                GotoLine(story, line_n - 5);
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
    }
    if (choices == 3)
    {
        int f1 = 0, f2 = 0, f3 = 0;
        while (f1 == 0 || f2 == 0 || f3 == 0)
        {
            option = check_tri(option);
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, line_n);
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
                    GotoLine(story, line_n + 2);
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
                    GotoLine(story, line_n + 4);
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
            if (f1 == 0 || f2 == 0 || f3 == 0)
            {
                GotoLine(story, line_n - 5);
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
    }
}
void customise_game()
{
    ifstream templat;
    templat.open("sa.txt");
    ofstream c_story;
    c_story.open("custom.txt");
    string s;
    string o = "$PN";
    while (getline(templat, s))
    {
        while (s.find(o, 0) < s.length())
            s.replace(s.find(o, 0), o.length(), playerName);

        c_story << s << endl;
    }
    templat.close();
    c_story.close();
}
void prologue();
void title();
void matilda();
void group1();
void group2();
void group3();
void woods();
void prologue()
{
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    int line_count = 0;
    GotoLine(story, 1);

    cls();

    while (line_count < 3)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
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
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    //cout<<"linefawk"<<line_count;
    int status;
    status = check_binary(status);

    if (status == 1)
    {
        title();
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
}
void title()
{
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);
    progress << "TITLE" << endl;
    cls();
    while (line_count < 26)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        if (line_count == 13)
        {
            line = line + " " + playerName;
            displaySlow(line);
        }
        else
            displaySlow(line);
        line_count++;
    }
    pod_conv(27, 4);
    /*int option;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    while (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
    {
        option=check_tri(getInputAsInt(option));
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
    }*/

    cls();
    line_count = 41;
    GotoLine(story, 42);
    while (line_count < 48)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
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
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    int option;
    //option(58,3);
    //question(58,2);

    int f1 = 0, f2 = 0, f3 = 0;
    while (f2 == 0)
    {
        option = check_tri(getInputAsInt(option));
        if (option == 1)
        {
            if (f1 == 0)
            {
                GotoLine(story, 58);
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
                GotoLine(story, 60);
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
                GotoLine(story, 62);
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
        else
        {
            cout << "No such option.." << endl;
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
    line_count = 65;
    GotoLine(story, 66);
    while (line_count < 69)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    cls();
    matilda();
}
void matilda()
{
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    progress << "MATILDA" << endl;
    line_count = 70;
    GotoLine(story, 71);
    while (line_count < 96)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }

    cls();
    //line_count=98;
    GotoLine(story, 98);
    while (line_count < 102)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    cout << endl;

    int f1 = 0, f2 = 0, f3 = 0;
    while (f3 == 0)
    {
        option = check_tri(getInputAsInt(option));
        if (option == 1)
        {
            if (f1 == 0)
            {
                GotoLine(story, 105);
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
                GotoLine(story, 107);
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
                GotoLine(story, 109);
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
        else
        {
            cout << "No such option.." << endl;
        }
        cout << endl;

        if (f3 == 0)
        {
            GotoLine(story, 100);
            int ln = 0;
            while (ln < 4)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            cout << endl;
        }
    }
    line_count = 111;
    GotoLine(story, 112);
    while (line_count < 115)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        line_count++;
    }
    cls();

    line_count = 116;
    GotoLine(story, 117);
    while (line_count < 126)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        line_count++;
    }
    cls();
    group1();
}
void group1()
{
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    progress << "GROUP1" << endl;
    int SPYBAR = 0;

group1:
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    int tea_talk = 0;

    line_count = 131;
    GotoLine(story, 132);
    while (line_count < 137)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        line_count++;
    }
    cout << endl;

    char house;
    while (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
    {
        cin >> house;
        if (house == 'A' || house == 'a')
        {
            if (h1 == 0)
            {
                GotoLine(story, 139);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    GotoLine(story, 140);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                }
                h1++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        else if (house == 'b' || house == 'B')
        {
            if (h2 == 0)
            {
                GotoLine(story, 142);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                h2++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        else if (house == 'C' || house == 'c')
        {
            if (h3 == 0)
            {
                GotoLine(story, 144);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    GotoLine(story, 145);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                }
                h3++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }

        else if (house == 'D' || house == 'd')
        {
            if (h4 == 0)
            {
                GotoLine(story, 147);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << "\n 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {

                    tea_talk++;
                    GotoLine(story, 148);
                    int ln = 0;
                    while (ln < 3)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    cout << "# What do you reply? \n1. Yes, of course. \n2. No, I am an atheist\n"
                         << endl;
                    int reply = check_binary(reply);
                    if (reply == 1)
                    {
                        cout << playerName + ": Yes, ofcourse." << endl;
                        GotoLine(story, 152);
                        //int ln=0;
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        cout << "#What so you reply\n1. This universe must be created by someone. \n"
                             << "2. On the grounds of modesty, I believe the presence of something powerful than humans.\n"
                             << "3. I have experienced his goodness and mercy.\n"
                             << endl;
                        int rep1;
                        cin >> rep1;
                        if (rep1 == 1)
                        {
                            cout << playerName + ": This universe must be created by someone." << endl;
                        }
                        else if (rep1 == 2)
                        {
                            cout << playerName + ": On the grounds of modesty, I believe the presence of something powerful than humans." << endl;
                        }
                        else if (rep1 == 3)
                        {
                            cout << playerName + ": I have experienced his goodness and mercy." << endl;
                        }
                        cout << "Customer4: See, even this foreigner believes in god." << endl;
                    }
                    else if (reply == 2)
                    {
                        //Atheist

                        cout << playerName + ": No, I am an atheist." << endl;
                        GotoLine(story, 152);
                        //int ln=0;
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        cout << "#What do you reply? \n1. It's the easiest answer for complex questions.\n"
                             << "2. God is just a delusional companion during hardships in the form of faith and hope.\n"
                             << "3. He was created to bring fear and order among the people.\n"
                             << endl;
                        int rep1;
                        cin >> rep1;
                        if (rep1 == 1)
                        {
                            cout << playerName + ": It's the easiest answer for complex questions." << endl;
                        }
                        else if (rep1 == 2)
                        {
                            cout << playerName + ": God is just a delusional companion during hardships in the form of faith and hope." << endl;
                        }
                        else if (rep1 == 3)
                        {
                            cout << playerName + ": He was created to bring fear and order among the people." << endl;
                        }
                        cout << "Customer4: See, even this foreigner is an atheist." << endl;
                    }
                    line_count = 159;
                    GotoLine(story, 160);
                    //int ln=0;
                    while (line_count < 165)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }
                    cls();
                }
                h4++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }

        if (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
        {
            GotoLine(story, 132);
            int ln = 0;
            while (ln < 6)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            cout << endl;
        }
    }
    //cls();
    if (tea_talk == 0)
    {
        cout << "You do not have enough clues" << endl;
        h4 = 0;
        goto group1;
    }
    else if (tea_talk == 1)
    {
        line_count = 166;
        GotoLine(story, 167);
        while (line_count < 174)
        {
            string line;
            getline(story, line, '\n');
            //story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        int f1 = 0, f2 = 0, f3 = 0;
        int ans = 0;
        while (ans == 0)
        {
            int option = check_tri(getInputAsInt(option));
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, 176);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f1++;
                    ans++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 2)
            {
                if (f2 == 0)
                {
                    GotoLine(story, 178);
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
                    GotoLine(story, 180);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f3++;
                    ans++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else
            {
                cout << "No such option.." << endl;
            }
            cout << endl;

            if (ans == 0)
            {
                GotoLine(story, 171);
                int ln = 0;
                while (ln < 4)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
                cout << endl;
            }
        }
        //pod_conv(175,3);
        cls();
        line_count = 182,
        GotoLine(story, 183);
        while (line_count < 188)
        {
            line.clear();
            getline(story, line, '\n');
            //story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }

        f1 = 0, f2 = 0, f3 = 0;
        ans = 0;
        while (ans == 0)
        {
            option = check_tri(getInputAsInt(option));
            if (option == 1)
            {
                if (f1 == 0)
                {
                    GotoLine(story, 190);
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
                    GotoLine(story, 192);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f2++;
                    ans++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 3)
            {
                if (f3 == 0)
                {
                    GotoLine(story, 194);
                    int ln = 0;
                    while (ln < 2)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    f3++;
                    ans++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else
            {
                cout << "No such option.." << endl;
            }
            cout << endl;

            if (ans == 0)
            {
                GotoLine(story, 185);
                int ln = 0;
                while (ln < 4)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
                cout << endl;
            }
        }
        //pod_conv(189,3);
        cls();
    }
    line_count = 199,
    GotoLine(story, 200);
    while (line_count < 202)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    //cls();
    while (line_count < 203)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }
    progress.close();
    story.close();
    cls();
    group2();
}
void group2()
{
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    progress << "GROUP2" << endl;

group2:
    int h1 = 0, h2 = 0, h3 = 0;
    GotoLine(story, 204);
    int ln = 0;
    while (ln < 5)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    cout << endl;

    int farmTalk = 0;
    while (h1 == 0 || h2 == 0 || h3 == 0)
    {
        cin >> house;
        if (house == 'e' || house == 'E')
        {
            if (h1 == 0)
            {
                GotoLine(story, 209);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << "\n 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {

                    farmTalk++;
                    cout << " *How do you start a conversation?/\n    1. Ask directions to the palace posing as foreigners\n    2. Talk about the pleasant weather" << endl;
                    int ans = check_binary(ans);
                    if (ans == 1)
                    {
                        SPYBAR += 50;
                        GotoLine(story, 210);
                        int ln = 0;
                        while (ln < 2)
                        {
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            ln++;
                        }
                    }
                    else if (ans == 2)
                    {
                        GotoLine(story, 212);
                        int ln = 0;
                        while (ln < 2)
                        {
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            ln++;
                        }
                    }
                    line_count = 213;
                    GotoLine(story, 214);
                    while (line_count < 231)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }
                    int f1 = 0, f2 = 0, f3 = 0;
                    while (f2 == 0)
                    {
                        int option = check_tri(getInputAsInt(option));
                        if (option == 1)
                        {
                            if (f1 == 0)
                            {
                                GotoLine(story, 232);
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
                                GotoLine(story, 234);
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
                                GotoLine(story, 236);
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
                        else
                        {
                            cout << "No such option.." << endl;
                        }
                        cout << endl;

                        if (f2 == 0)
                        {
                            GotoLine(story, 226);
                            int ln = 0;
                            while (ln < 5)
                            {
                                string lin;
                                getline(story, lin, '\n');
                                displaySlow(lin);
                                ln++;
                            }
                            cout << endl;
                        }
                    }
                    cls();

                    GotoLine(story, 238);
                    int ln = 0;
                    while (ln < 4)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                    cout << endl;
                }
                h1++;
            }

            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }

        else if (house == 'f' || house == 'F')
        {
            if (h2 == 0)
            {
                GotoLine(story, 244);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                h2++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }

        else if (house == 'g' || house == 'G')
        {
            if (h3 == 0)
            {
                GotoLine(story, 246);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    SPYBAR += 100;

                    GotoLine(story, 247);
                    int ln = 0;
                    while (ln < 3)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        ln++;
                    }
                }
                else if (choice == 2)
                {
                    cout << "You: No thanks.." << endl;
                }
                h3++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }

        if (h1 == 0 || h2 == 0 || h3 == 0)
        {
            GotoLine(story, 204);
            int ln = 0;
            while (ln < 5)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            cout << endl;
        }
    }
    if (farmTalk == 0)
    {
        cout << "You don't have necessary clues" << endl;
        h1 = 0;
        goto group2;
    }
    cout << "SPYBAR: " << SPYBAR << endl;
    if (SPYBAR >= 100)
    {
        cout << "You talked with spies or caused discomfort among people... "
             << "\nRestarting investigation in the colonies" << endl;
        SPYBAR = 0,
        //h1=0,h2=0,h3=0,h4=0;
            tea_talk = 0, farmTalk = 0;
        group1();
    }
    progress.close();
    story.close();
    group3();
}
void group3()
{
    //cls();
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    progress << "GROUP3";
group3:
    int cobbler_talk = 0;
    GotoLine(story, 252);
    int ln = 0;
    while (ln < 6)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    while (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
    {
        cin >> house;
        if (house == 'H' || house == 'h')
        {
            if (h1 == 0)
            {
                GotoLine(story, 259);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    GotoLine(story, 260);
                    lin.clear();
                    getline(story, lin, '\n');
                    displaySlow(lin);
                }
                h1++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        else if (house == 'I' || house == 'i')
        {
            if (h2 == 0)
            {
                GotoLine(story, 262);
                int ln = 0;
                while (ln < 6)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    GotoLine(story, 268);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                }
                h2++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        else if (house == 'J' || house == 'j')
        {
            if (h3 == 0)
            {
                GotoLine(story, 270);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    SPYBAR += 100;
                    GotoLine(story, 271);
                    lin.clear();
                    getline(story, lin, '\n');
                    displaySlow(lin);
                }
                h3++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        else if (house == 'K' || house == 'k')
        {
            if (h4 == 0)
            {
                GotoLine(story, 273);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    cobbler_talk++;
                    GotoLine(story, 275);
                    string lin;
                    line_count = 274;
                    while (line_count < 289)
                    {
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }
                }
                h4++;
            }
            else
            {
                cout << "Podrick: We visited this house just now" << endl;
            }
        }
        if (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
        {
            GotoLine(story, 252);
            int ln = 0;
            while (ln < 6)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            cout << endl;
        }
    }
    if (cobbler_talk == 1)
    {
        GotoLine(story, 291);
        ln = 0;
        while (ln < 11)
        {
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            ln++;
        }
        int f1 = 0, f2 = 0, f3 = 0;
        while (f2 == 0 && f3 == 0)
        {
            cin >> option;
            option = check_tri(option);
            if (option == 1 && f1 == 0)
            {
                GotoLine(story, 302);
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
            else if (option == 2)
            {
                GotoLine(story, 304);
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
            else if (option == 3)
            {
                GotoLine(story, 306);
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
            if (f2 == 0 && f3 == 0)
            {
                GotoLine(story, 298);
                ln = 0;
                while (ln < 4)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
            }
        }
        cls();
        GotoLine(story, 308);
        ln = 0;
        while (ln < 14)
        {
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            ln++;
        }
        f1 = 0, f2 = 0, f3 = 0;
        while (f2 == 0)
        {
            cin >> option;
            option = check_tri(option);
            if (option == 1 && f1 == 0)
            {
                GotoLine(story, 322);
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
            else if (option == 2)
            {
                GotoLine(story, 324);
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
            else if (option == 3 && f3 == 0)
            {
                GotoLine(story, 326);
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
            if (f2 == 0)
            {
                GotoLine(story, 318);
                ln = 0;
                while (ln < 4)
                {
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    ln++;
                }
            }
        }
        //system("pause");
        cls();
        GotoLine(story, 330);
        ln = 0;
        while (ln < 18)
        {
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            ln++;
        }
        // system("pause");
        cls();
        woods();
    }
    else
    {
        cout << "Not enough clues to move on." << endl;
        goto group3;
    }
    cout << "SPYBAR: " << SPYBAR << endl;
    if (SPYBAR >= 100)
        group1();

    progress.close();
}
void woods()
{
    string message;
    fstream story;
    story.open("custom.txt");

    fstream progress;
    progress.open("progress.txt", ios::app);

    progress << "WOODS";
woods:

    GotoLine(story, 348);
    int ln = 0;
    while (ln < 10)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    cls();
    GotoLine(story, 359);
    ln = 0;
    while (ln < 6)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    while (f2 == 0 && f5 == 0)
    {
        cin >> option;
        option = check_penta(option);
        if (option == 1 && f1 == 0)
        {
            GotoLine(story, 366);
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
        else if (option == 2)
        {
            GotoLine(story, 368);
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
        else if (option == 3 && f3 == 0)
        {
            GotoLine(story, 370);
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
        else if (option == 4 && f4 == 0)
        {
            GotoLine(story, 372);
            int ln = 0;
            while (ln < 2)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            f4++;
        }
        else if (option == 5)
        {
            GotoLine(story, 374);
            int ln = 0;
            while (ln < 2)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
            f5++;
        }
        else
            displaySlow("Podrick: We already talked about this");
        if (f2 == 0 && f5 == 0)
        {
            GotoLine(story, 318);
            ln = 0;
            while (ln < 4)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
        }
    }
    GotoLine(story, 377);
    ln = 0;
    while (ln < 14)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    f1 = 0;
    int i = 0;
    while (f1 == 0)
    {
        GotoLine(story, 391);
        ln = 0;
        while (ln < 3)
        {
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            ln++;
        }
        cin >> option;
        option = check_two(option);
        if (option == 1)
        {
            cout << "Type your guess" << endl;
            cin.ignore();
            getline(cin, message);
            if (toSmall(message) == "heat the paper")
            {
                f1 = 1;
                cout << "Your guess is reight!" << endl;
            }
            else
                cout << "Your guess is wrong!" << endl;
        }
        else
        {
            ++i;
            if (i == 1)
                cout << "The paper is folded at the bottom left corner. You open it to see the number 5. Can you guess now?" << endl;
            if (i == 2)
            {
                cout << "After a few minutes, you finally decoded the message.(Or) Shift the letter by -5 for example F->A" << endl;
                f1 = 1;
            }
        }
    }
    GotoLine(story, 394);
    ln = 0;
    while (ln < 9)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    f1 = 0;
    while (f1 == 0)
    {
        cin >> option;
        option = check_two(option);
        if (option == 1)
        {
            cout << "Challenge Accepted" << endl;
            f1 = 1;
        }
        else
        {
            cout << "Ivan fears that it could be Matilda who they will kill if you don’t go. For their sake, you accept to go." << endl;
            cout << "Game proceeds only if you accept the challenge" << endl;
            GotoLine(story, 400);
            ln = 0;
            while (ln < 3)
            {
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                ln++;
            }
        }
    }
    GotoLine(story, 404);
    ln = 0;
    while (ln < 12)
    {
        string lin;
        getline(story, lin, '\n');
        displaySlow(lin);
        ln++;
    }
    cls();
    GotoLine(story,417);
    ln=0;
    while(ln<2)
    {
        string lin;
        getline(story,lin,'\n');
        displaySlow(lin);
        ln++;
    }

}
int main()
{
    std::vector<string> story_line;
    string line;

    cout << "Enter a name for your character: ";
    cin >> playerName;

    customise_game();

    fstream story;
    story.open("custom.txt");

    ifstream checkpnt;
    checkpnt.open("progress.txt");
    string checkpoint;
    int c_p = 0;
    std::vector<string> checkp;
    while (checkpnt.good())
    {
        getline(checkpnt, checkpoint, '\n');
        checkp.push_back(checkpoint);
        c_p++;
    }
    if (checkpoint != "")
    {
        cout << "Last checkpoint: " << checkp[c_p - 2] << endl;
        checkpoint = checkp[c_p - 2];
    }
    if (checkpoint == "GROUP1")
        group1();
    else if (checkpoint == "GROUP2")
        group2();
    else if (checkpoint == "TITLE")
        title();
    else if (checkpoint == "TITLE")
        matilda();
    //checkpnt.close();
    else
        prologue();

    system("pause");

    return 0;
}

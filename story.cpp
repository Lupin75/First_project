#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "./resources/hpps/global.hpp"
/*
    Last modified by: Abishek.r
    Last modified   : 16-06-2020
    Filename        : story.cpp
    Description     : Removed redundant code for displaying story
*/

using namespace std;
void cls()
{
    system("pause");
    system("cls");
}

void displaySlow(string line, int speed = 100000, bool sleepStats = true)
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
void displayStory(fstream &fpr, int start, int end)
{
    GotoLine(fpr, start);
    int ln = start;
    while (ln <= end)
    {
        string lin;
        getline(fpr, lin, '\n');
        displaySlow(lin);
        ln++;
    }
}
//Overloaded to display 1 line
void displayStory(fstream &fpr, int start)
{
    GotoLine(fpr, start);
    //int ln = start;
    string lin;
    getline(fpr, lin, '\n');
    displaySlow(lin);
}

void pod_conv(int line_n=27, int choices=4)
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

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
                    displayStory(story,line_n,28);
                    f1++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 2)
            {
                if (f2 == 0)
                {
                    displayStory(story,line_n+2,30);
                    f2++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 3)
            {
                if (f3 == 0)
                {
                    displayStory(story,line_n+4,32);
                    f3++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 4)
            {
                if (f4 == 0)
                {
                    displayStory(story,line_n+6,39);
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
                displayStory(story,line_n-5,26);
            }
        }
    }
}
void customise_game()
{
    ifstream templat;
    templat.open("./resources/txtFiles/sa.txt");
    ofstream c_story;
    c_story.open("./resources/txtFiles/custom.txt");
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
void finding_princess();
void prologue()
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    int line_count = 0;
    //GotoLine(story, 1);

    cls();

    displayStory(story,1,3);
    /*while (line_count < 3)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }*/
    //line_count=0;
    cout << endl;
    cls();
    //cout<<"    ";
    displayStory(story,4,10);
    /*while (line_count < 10)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }*/
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
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);
    progress << "TITLE" << endl;
    cls();
    displayStory(story,12,26);
    /*
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
    }*/
    pod_conv();
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
    //line_count = 41;
    displayStory(story,41,47);
    cls();
    displayStory(story,49,57);
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
                displayStory(story,58,59);
                f1++;
            }
            else
                displaySlow("Podrick: We already talked about this");
        }
        else if (option == 2)
        {
            if (f2 == 0)
            {
                displayStory(story,60,61);
                f2++;
            }
            else
                displaySlow("Podrick: We already talked about this");
        }
        else if (option == 3)
        {
            if (f3 == 0)
            {
                displayStory(story,62,63);
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
            displayStory(story,54,57);
        }
    }
    // my code
    cls();
    line_count = 65;
    displayStory(story,66,69);
    cls();
    matilda();
}
void matilda()
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    progress << "MATILDA" << endl;
    line_count = 70;
    displayStory(story,71,96);
    cls();
    //line_count=98;
    displayStory(story,98,103);
    cout << endl;

    int f1 = 0, f2 = 0, f3 = 0;
    while (f3 == 0)
    {
        option = check_tri(getInputAsInt(option));
        if (option == 1)
        {
            if (f1 == 0)
            {
               displayStory(story,105,106);
                f1++;
            }
            else
                displaySlow("Podrick: We already talked about this");
        }
        else if (option == 2)
        {
            if (f2 == 0)
            {
                displayStory(story,107,108);
                f2++;
            }
            else
                displaySlow("Podrick: We already talked about this");
        }
        else if (option == 3)
        {
            if (f3 == 0)
            {
                displayStory(story,109,110);
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
            displayStory(story,100,103);
            cout << endl;
        }
    }
    line_count = 111;
    displayStory(story,112,115);
    cls();

    line_count = 116;
    displayStory(story,117,125);
    cls();
    group1();
}
void group1()
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    progress << "GROUP1" << endl;
    int SPYBAR = 0;

group1:
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    int tea_talk = 0;

    line_count = 131;
    displayStory(story,132,138);
    cout << endl;

    char house;
    while (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
    {
        cin >> house;
        if (house == 'A' || house == 'a')
        {
            if (h1 == 0)
            {
                displayStory(story,139);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                   displayStory(story,140);
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
                displayStory(story,142);
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
                displayStory(story,144);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    displayStory(story,145);
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
                displayStory(story,147);
                cout << "\n 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {

                    tea_talk++;
                    displayStory(story,148,149);
                    cout << "# What do you reply? \n1. Yes, of course. \n2. No, I am an atheist\n"
                         << endl;
                    int reply = check_binary(reply);
                    if (reply == 1)
                    {
                        cout << playerName + ": Yes, ofcourse." << endl;
                        displayStory(story,152);
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
                        cout << "Customer 4: See, even this foreigner believes in god." << endl;
                    }
                    else if (reply == 2)
                    {
                        //Atheist

                        cout << playerName + ": No, I am an atheist." << endl;
                        displayStory(story,152);
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
                        cout << "Customer 4: See, even this foreigner is an atheist." << endl;
                    }
                    line_count = 159;
                    GotoLine(story, 160);
                    //int ln=0;
                    displayStory(story,160,165);
                    /*
                    while (line_count < 165)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }*/
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
            displayStory(story,132,137);
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
        //line_count = 166;
        //GotoLine(story, 167);
        displayStory(story,167,174);
        /*while (line_count < 174)
        {
            string line;
            getline(story, line, '\n');
            //story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }*/
        int f1 = 0, f2 = 0, f3 = 0;
        int ans = 0;
        while (ans == 0)
        {
            int option = check_tri(getInputAsInt(option));
            if (option == 1)
            {
                if (f1 == 0)
                {
                    displayStory(story,176,177);
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
                    displayStory(story,178,179);
                    f2++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 3)
            {
                if (f3 == 0)
                {
                    displayStory(story,180,181);
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
                displayStory(story,171,174);
                cout << endl;
            }
        }
        //pod_conv(175,3);
        cls();
        displayStory(story,183,188);
        /*line_count = 182,
        GotoLine(story, 183);
        while (line_count < 188)
        {
            line.clear();
            getline(story, line, '\n');
            //story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }*/

        f1 = 0, f2 = 0, f3 = 0;
        ans = 0;
        while (ans == 0)
        {
            option = check_tri(getInputAsInt(option));
            if (option == 1)
            {
                if (f1 == 0)
                {
                    displayStory(story,190,191);
                    f1++;
                }
                else
                    displaySlow("Podrick: We already talked about this");
            }
            else if (option == 2)
            {
                if (f2 == 0)
                {
                    displayStory(story,192,193);
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
                    displayStory(story,194,195);
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
                displayStory(story,185,188);
                cout << endl;
            }
        }
        //pod_conv(189,3);
        cls();
    }
    displayStory(story,200,202);
    /*line_count = 199,
    GotoLine(story, 200);
    while (line_count < 202)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }*/
    //cls();
    /*while (line_count < 203)
    {
        line.clear();
        getline(story, line, '\n');
        //story_line.push_back(line);
        displaySlow(line);
        line_count++;
    }*/
    progress.close();
    story.close();
    cls();
    group2();
}
void group2()
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    progress << "GROUP2" << endl;

group2:
    int h1 = 0, h2 = 0, h3 = 0;
    displayStory(story,204,208);
    cout << endl;

    int farmTalk = 0;
    while (h1 == 0 || h2 == 0 || h3 == 0)
    {
        cin >> house;
        if (house == 'e' || house == 'E')
        {
            if (h1 == 0)
            {
                displayStory(story,209);
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
                        displayStory(story,211,212);
                    }
                    else if (ans == 2)
                    {
                        displayStory(story,213,214);
                    }
                    displayStory(story,215,231);
                    cout<<endl;
                    /*line_count = 213;
                    GotoLine(story, 214);
                    while (line_count < 231)
                    {
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }*/
                    int f1 = 0, f2 = 0, f3 = 0;
                    while (f2 == 0)
                    {
                        int option = check_tri(getInputAsInt(option));
                        if (option == 1)
                        {
                            if (f1 == 0)
                            {
                                displayStory(story,232,233);
                                f1++;
                            }
                            else
                                displaySlow("Podrick: We already talked about this");
                        }
                        else if (option == 2)
                        {
                            if (f2 == 0)
                            {
                                displayStory(story,234,235);
                                f2++;
                            }
                            else
                                displaySlow("Podrick: We already talked about this");
                        }
                        else if (option == 3)
                        {
                            if (f3 == 0)
                            {
                                displayStory(story,236,237);
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
                            displayStory(story,227,231);
                            cout << endl;
                        }
                    }
                    cls();

                    displayStory(story,239,242);
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
                displayStory(story,244);
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
                displayStory(story,246,247);
                /*GotoLine(story, 246);
                string lin;
                getline(story, lin, '\n');
                displaySlow(lin);
                getline(story, lin, '\n');
                displaySlow(lin);*/
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    SPYBAR += 100;

                    displayStory(story,248,250);
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
            displayStory(story,204,208);
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
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    progress << "GROUP3"<<endl;
group3:
    int cobbler_talk = 0;
    displayStory(story,252,258);
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    while (h1 == 0 || h2 == 0 || h3 == 0 || h4 == 0)
    {
        cin >> house;
        if (house == 'H' || house == 'h')
        {
            if (h1 == 0)
            {
                displayStory(story,259);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                   displayStory(story,260);
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
                displayStory(story,262,267);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    displayStory(story,268);
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
                displayStory(story,270);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    SPYBAR += 100;
                    displayStory(story,271);
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
                displayStory(story,273);
                cout << " 1. Talk\n 2. Move" << endl;
                int choice = check_binary(choice);
                if (choice == 1)
                {
                    cobbler_talk++;
                    displayStory(story,274,289);
                    /*GotoLine(story, 275);
                    string lin;
                    line_count = 274;
                    while (line_count < 289)
                    {
                        getline(story, lin, '\n');
                        displaySlow(lin);
                        line_count++;
                    }*/
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
            displayStory(story,252,257);
            cout << endl;
        }
    }
    if (cobbler_talk == 1)
    {
        displayStory(story,291,301);
        cout<<endl;
        int f1 = 0, f2 = 0, f3 = 0;
        while (f2 == 0 && f3 == 0)
        {
            cin >> option;
            option = check_tri(option);
            if (option == 1 && f1 == 0)
            {
                displayStory(story,302,301);
                f1++;
            }
            else if (option == 2)
            {
                displayStory(story,304,305);
                f2++;
            }
            else if (option == 3)
            {
                displayStory(story,306,307);
                f3++;
            }
            else
                displaySlow("Podrick: We already talked about this");
            if (f2 == 0 && f3 == 0)
            {
                displayStory(story,298,301);
                cout<<endl;
            }
        }
        cls();
        displayStory(story,308,321);
        cout<<endl;
        f1 = 0, f2 = 0, f3 = 0;
        while (f2 == 0)
        {
            cin >> option;
            option = check_tri(option);
            if (option == 1 && f1 == 0)
            {
                displayStory(story,322,323);
                f1++;
            }
            else if (option == 2)
            {
                displayStory(story,324,325);
                f2++;
            }
            else if (option == 3 && f3 == 0)
            {
                displayStory(story,326,327);
                f3++;
            }
            else
                displaySlow("Podrick: We already talked about this");
            if (f2 == 0)
            {
                displayStory(story,318,321);
                cout<<endl;
            }
        }
        //system("pause");
        cls();
        displayStory(story,330,346);
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
    story.open("./resources/txtFiles/custom.txt");

    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);

    progress << "WOODS"<<endl;
woods:

    displayStory(story,348,357);
    cls();
    displayStory(story,359,365);
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    int ans = 0;
    while (ans != 2)
    {
        cin >> option;
        option = check_penta(option);
        if (option == 1 && f1 == 0)
        {
            displayStory(story,366,367);
            f1++;
        }
        else if (option == 2 && f2 == 0)
        {
            displayStory(story,368,369);
            f2++;
            ans++;
        }
        else if (option == 3 && f3 == 0)
        {
            displayStory(story,370,371);
            f3++;
        }
        else if (option == 4 && f4 == 0)
        {
            displayStory(story,372,373);
            f4++;
        }
        else if (option == 5 && f5==0)
        {
            displayStory(story,374,375);
            f5++;
            ans++;
        }
        else
            displaySlow("Podrick: We already talked about this");
        if (f2 == 0 || f5 == 0)
        {
            displayStory(story,359,364);
            cout<<endl;
        }
    }
    displayStory(story,379,389);
    f1 = 0;
    int i = 0;
    while (f1 == 0)
    {
        displayStory(story,390,393);
        cin >> option;
        option = check_two(option);
        if (option == 1)
        {
            cout << "Type your guess:" << endl;
            cin.ignore();
            getline(cin, message);
            if (toSmall(message) == "heat the paper")
            {
                f1 = 1;
                cout << "Your guess is right!" << endl;
            }
            else
                cout << "Your guess is wrong!" << endl;
        }
        else
        {
            ++i;
            if (i == 1)
                cout << "The paper is folded at the bottom left corner. You open it to see the number 5. Can you guess now?" << endl;
            //Can add one more chance or player
            if (i == 2)
            {
                cout << "***Hint: Shift the letter by -5, for example F->A" << endl;
                f1 = 1;
            }
            if(i ==3){
                cout << "After a few minutes, you finally decoded the message.(Or) Shift the letter by -5 for example F->A" << endl;
                f1 = 1;
            }
        }
    }
    displayStory(story,394,403);
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
            displayStory(story,400,402);
        }
    }
    displayStory(story,404,419);
    cls();
    cout<<"***********call fight function************"<<endl;
    cls();
    finding_princess();
}
void finding_princess()
{
    fstream story;
    story.open("./resources/txtFiles/custom.txt");
    fstream progress;
    progress.open("./resources/txtFiles/progress.txt", ios::app);
    progress << "FIND PRINCESS"<<endl;
    find_princess:
    displayStory(story,420,431);
    cls();
    displayStory(story,433,447);
    cls();
    displayStory(story,450,470);
    cls();
    displayStory(story,472,474);
    // function to dodge
    // if dodge success
    cls();
    displayStory(story,477,495);
    cls();
    displayStory(story,498,505);
    int f1=0,f2=0,f3=0;
    while(f3==0)
    {
        cin>>option;
        option=check_tri(option);
        if(option==1&&f1==0)
        {
            displayStory(story,506,507);
            f1++;
        }
        else if(option==2&&f2==0)
        {
            displayStory(story,508,509);
            f2++;
        }
        else if(option==3)
        {
            displayStory(story,511,513);
            f3++;
        }
        else
            displaySlow("Just now you thought of it!");
        if(f3==0)
        {
            displayStory(story,501,505);
        }
    }
    cls();
    displayStory(story,516,523);
    cls();
    displayStory(story,526,534);
    f1=0,f2=0,f3=0;
    while(f3==0)
    {
        cin>>option;
        option=check_tri(option);
        if(option==1&&f1==0)
        {
            displayStory(story,535,536);
            f1++;
        }
        else if(option==2&&f2==0)
        {
            displayStory(story,537,538);
            f2++;
        }
        else if(option==3)
        {
            displayStory(story,539,540);
            f3++;
        }
        else
            displaySlow("Podrick: We just talked about this");
        if(f3==0)
        {
            displayStory(story,530,534);
        }
    }
    displayStory(story,542,546);
    cls();
    displayStory(story,549,558);
    f1=0,f2=0,f3=0;
    while(f1==0&&f3==0)
    {
        cin>>option;
        option=check_tri(option);
        if(option==1)
        {
            displayStory(story,559,560);
            f1++;
        }
        else if(option==2&&f2==0)
        {
            displayStory(story,561,562);
            f2++;
        }
        else if(option==3)
        {
            displayStory(story,563,564);
            f3++;
        }
        else 
            displaySlow("Podrick: We just talked about this");
        if(f1==0 && f3==0)
        {
            displayStory(story,553,558);
        }
    }
    displayStory(story,566,569);
    cls();
    //maze();

}
int main()
{
    std::vector<string> story_line;
    string line;

    cout << "Enter a name for your character: ";
    cin >> playerName;

    customise_game();
    fstream story;
    story.open("./resources/txtFiles/custom.txt");

    ifstream checkpnt;
    checkpnt.open("./resources/txtFiles/progress.txt");
    string checkpoint;
    
    int c_p = 0;
    std::vector<string> checkp;
    while (checkpnt.good())
    {
        getline(checkpnt, checkpoint, '\n');
        //cout<<checkpoint<<endl;
        checkp.push_back(checkpoint);
        c_p++;
    }
    //cout<<"CHECK !";
    
    //cout<<"Number of checkpoints: "<<c_p<<endl;
    if (checkpoint == ""&& checkp.size()>1)
    {
        //cout << "Last checkpoint: " << checkp[c_p - 2] << endl;
        checkpoint = checkp[c_p - 2];
    }
    //cout<<"CHECK @";
    
    cout << "Last checkpoint: " << checkpoint << endl;
    //system("pause");
    if (checkpoint == "GROUP1")
        group1();
    else if (checkpoint == "GROUP2")
        group2();
    else if (checkpoint == "TITLE")
        title();
    else if (checkpoint == "MATILDA")
        matilda();
    else if (checkpoint == "GROUP3")
        group3();
    else if (checkpoint == "WOODS")
        woods();
    else if (checkpoint == "FIND PRINCESS")
        finding_princess();
    //checkpnt.close();
    else
        prologue();
    //finding_princess();
    system("pause");

    return 0;
}

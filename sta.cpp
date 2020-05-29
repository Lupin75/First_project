#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "global.hpp"
/*
    Last modified by: Nirmal Kumar
    Created on      : 21 05, 2020
    Last modified   : 29/5/2020 3:00 AM
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
void pod_conv(int line_n=27,int choices=4){
    fstream story;
    story.open("sa.txt");
    GotoLine(story,line_n);

    int option;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    while (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
    {
        option=check_pc_option(getInputAsInt(option));
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
                GotoLine(story, line_n+2);
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
                GotoLine(story, line_n+4);
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
                GotoLine(story, line_n+6);
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
        else{
            cout<<"No such option is present"<<endl;
        }
        cout << endl;

        if (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0)
        {
             GotoLine(story, line_n-5);
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

int main()
{
    std::vector<string> story_line;
    string line;
    string bold;
    fstream story;
    story.open("sa.txt");
    int line_count = 0;
    cout<<"Enter a name for your character: ";
    cin>>playerName;
    system("cls");
    
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
    status=check_status(getInputAsInt(status));

    if (status == 1)
    {
        system("cls");
        while (line_count < 26)
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
        pod_conv();
        /*int option;
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
        }*/
        
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
        int option;
        //option(58,3);
        //question(58,2);
        
        int f1 = 0, f2 = 0, f3 = 0;
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
            else{
                cout<<"No such option.."<<endl;
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
        while (line_count < 96)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        
        cls();
        //line_count=98;
        GotoLine(story,98);
        while (line_count < 102)
        {
            line.clear();
            getline(story, line, '\n');
            story_line.push_back(line);
            displaySlow(line);
            line_count++;
        }
        cout<<endl;

        f1 = 0, f2 = 0, f3 = 0;
        while (f3 == 0)
        {
            cin >> option;
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
            else{
                cout<<"No such option.."<<endl;
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
                cout<<endl;
            }
        }
        line_count=111;
        GotoLine(story,112);
        while (line_count < 115){
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            line_count++;
        }
        cls();
        

        line_count=116;
        GotoLine(story,117);
        while (line_count < 126){
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            line_count++;
        }
        cls();
                
        line_count=131;
        GotoLine(story,132);
        while (line_count < 137){
            string lin;
            getline(story, lin, '\n');
            displaySlow(lin);
            line_count++;
        }
        cout<<endl;
        int h1=0,h2=0,h3=0,h4=0;
        char house;
        while(h1==0||h2==0||h3==0||h4==0){
            cin>>house;
            if(house=='A'||house=='a'){
                if(h1==0){
                    GotoLine(story,139);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    cout<<" 1. Talk\n 2. Move"<<endl;
                    int choice=check_status(getInputAsInt(choice));
                    if (choice==1){
                        GotoLine(story,140);
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                    }
                    h1++;
                }
                else{
                    cout<<"Podrick: We visited this house just now"<<endl;
                }
            }
            else if(house=='b'||house=='B'){
                if(h2==0){
                    GotoLine(story,142);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    h2++;
                }
                else{
                    cout<<"Podrick: We visited this house just now"<<endl;
                }
            }
            else if(house=='C'||house=='c'){
                if(h3==0){
                    GotoLine(story,144);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    cout<<" 1. Talk\n 2. Move"<<endl;
                    int choice=check_status(getInputAsInt(choice));
                    if (choice==1){
                        GotoLine(story,145);
                        string lin;
                        getline(story, lin, '\n');
                        displaySlow(lin);
                    }
                    h3++;
                }
                else{
                    cout<<"Podrick: We visited this house just now"<<endl;
                }
            }
            
            if(house=='D'||house=='d'){
                if(h4==0){
                    GotoLine(story,147);
                    string lin;
                    getline(story, lin, '\n');
                    displaySlow(lin);
                    cout<<"\n 1. Talk\n 2. Move"<<endl;
                    int choice=check_status(getInputAsInt(choice));
                    if (choice==1){
                        GotoLine(story,148);
                        int ln=0;
                        while(ln<3){
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            ln++;
                        }
                        cout<<"# What do you reply? \n 1. Yes, of course. \n2. No, I am an atheist\n"<<endl;
                        int reply=check_status(getInputAsInt(reply));
                        if(reply==1){
                            cout<<"You: Yes, ofcourse."<<endl;
                            GotoLine(story,152);
                            //int ln=0;
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            cout<<"#What so you reply\n1. This universe must be created by someone. \n"
                            <<"2. On the grounds of modesty, I believe the presence of something powerful than humans.\n"
                            <<"3. I have experienced his goodness and mercy.\n"<<endl;
                            int rep1;
                            cin>>rep1;
                            if(rep1==1){
                                cout<<"You: This universe must be created by someone."<<endl;
                            }
                            else if(rep1==2){
                                cout<<"You: On the grounds of modesty, I believe the presence of something powerful than humans."<<endl;
                            }    
                            else if(rep1==3){
                                cout<<"You: I have experienced his goodness and mercy."<<endl;
                            }
                            cout<<"See, even this foreigner believes in god."<<endl;
                        }
                        else if(reply==2){
                            //Atheist
                            
                            cout<<"You: No, I am an atheist."<<endl;
                            GotoLine(story,152);
                            //int ln=0;
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            cout<<"#What do you reply? \n1. It's the easiest answer for complex questions.\n"
                            <<"2. God is just a delusional companion during hardships in the form of faith and hope.\n"
                            <<"3. He was created to bring fear and order among the people.\n"<<endl;
                            int rep1;
                            cin>>rep1;
                            if(rep1==1){
                                cout<<"You: It's the easiest answer for complex questions."<<endl;
                            }
                            else if(rep1==2){
                                cout<<"You: God is just a delusional companion during hardships in the form of faith and hope."<<endl;
                            }    
                            else if(rep1==3){
                                cout<<"You: He was created to bring fear and order among the people."<<endl;
                            }
                            cout<<"See, even this foreigner is an atheist."<<endl;
                        }
                        line_count=159;
                        GotoLine(story,160);
                        //int ln=0;
                        while(line_count<165){
                            string lin;
                            getline(story, lin, '\n');
                            displaySlow(lin);
                            line_count++;
                        }
                        cls();   

                            
                    }
                    h4++;
                }
                else{
                    cout<<"Podrick: We visited this house just now"<<endl;
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
                    cout<<endl;
            }
        }
         
        
        /*line_count = 90;
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

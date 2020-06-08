//g++ -std=c++17 jump.cpp -D_WIN32_WINNT=0x0A00
/*
    haven't tested if this works or not but , i hope it does.
    i felt like keeping pokemon(original) style fighting here will be weird, so i added this, hope you guys like it.
    okay, this is how it works, we have a namespace called `fightFunction` (dont ask me why i named it function eventho it's not a function)
    this namespace contains fiveSeconds, doProceed , didFunctionQuit and countDown function and reset function.
    call countDown in a seperate thread, and a while loop in the main function.
    in main function , keep checking didFunctionQuit is false or not. if true exit the loop.
    in main  function, take input `didTheUserType`.  and Sleep for 1 second.why, because there will be a case that the countDown function quits while the the main function is IN THE WHILE LOOP.
    to counter this, we need a delay.             (EDIT:(this whole para symplified)Sleep to maintain syncronization between the two threads).
    the delay can be anything as long as the we have sync between the two threads.
*/
#include<iostream>
#include<ctime>
#include "mingw.thread.h"
#include<Windows.h>
namespace fightFunction{
    std::string didTheUserType = "NO";
    int fiveSeconds = 5;
    bool doProceed = false;
    bool didFunctionQuit = false;
    void countDown(std::string whatIsTheWord){
        while(fightFunction::fiveSeconds != 0 && fightFunction::doProceed !=true){
            std::cout<<fightFunction::fiveSeconds<<std::endl;
            fightFunction::fiveSeconds--;
            Sleep(1000);
            if(fightFunction::didTheUserType == whatIsTheWord){
                fightFunction::doProceed = true;
            }else if(fightFunction::didTheUserType != "NO"){
                std::cout<<"nope!try again"<<std::endl;
                fightFunction::didTheUserType = "NO";
            }
            fightFunction::didFunctionQuit = true;
        }
    }
    void reset(){
        fightFunction::didFunctionQuit = false;
        fightFunction::fiveSeconds = 5;
        fightFunction::didTheUserType="NO";
        fightFunction::doProceed = false;
        fightFunction::didFunctionQuit = false;
    }
} // namespace fightFunction

class Fighting{
    private:
    std::string playerName;// i don't know if need these two or not. anyway , i included this here, you can remove it if you dont want to tho.
    std::string enemyName;// i don't know if need these two or not. anyway , i included this here, you can remove it if you dont want to tho.

    void generateRandomEvent(){
        srand(time(NULL));
        int i = rand()%2;
        if(i == 0){
            // case 0://0 for attack
            std::thread th( fightFunction::countDown,"attack");
            while(fightFunction::didFunctionQuit == false){
                std::cin>>fightFunction::didTheUserType;
                Sleep(1000);
            }
            th.join();
            fightFunction::reset();
        }else if(i ==1){
            // case 1://1 for shield
            std::thread th(fightFunction::countDown,"shield");//shield or defence or whatever
            while(fightFunction::didFunctionQuit == false){
                std::cin>>fightFunction::didTheUserType;
                Sleep(1000);
            }
            th.join();
            fightFunction::reset();
        }else if(i == 2){
            // case 2://2 for jump
            std::thread th(fightFunction::countDown,"jump");//jump back for a successful dodge
            while(fightFunction::didFunctionQuit==false){
                std::cin>>fightFunction::didTheUserType;
                Sleep(1000);
            }
            th.join();
            fightFunction::reset();
        }
    }
    public:
    //constructor
    // i don't know if need constructor .anyway i included this here, you can remove it if you dont want to tho.
    Fighting(std::string pn,std::string en){
        this->playerName = pn;
        this->enemyName = en;
    }
};
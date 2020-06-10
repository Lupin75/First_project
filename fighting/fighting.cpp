//  g++ -std=c++17 fighting.cpp -D_WIN32_WINNT=0x0A00
/*

    (new)since im using random number generator for enemy movement patterns, the enemy has dumbest AI ever.

    (old)haven't tested if this works or not but , i hope it does.
    i felt like keeping pokemon(original) style fighting here will be weird, so i added this, hope you guys like it.
    okay, this is how it works, we have a namespace called `fightFunction` (dont ask me why i named it function eventho it's not a function)
    this namespace contains fiveSeconds, doProceed , didFunctionQuit and countDown function and reset function.
    call countDown in a seperate thread, and a while loop in the main function.
    in main function , keep checking didFunctionQuit is false or not. if true exit the loop.
    in main  function, take input `didTheUserType`.  and Sleep for 1 second.why, because there will be a case that the countDown function quits while the the main function is IN THE WHILE LOOP.
    to counter this, we need a delay.             (EDIT:(this whole para symplified)Sleep to maintain syncronization between the two threads).
    the delay can be anything as long as the we have sync between the two threads.
*/
int playerHealth = 100;//remove this and include global.hpp
int playerDefendStat = 50;
//#include"global.hpp
// #include"global.hpp"
#include<iostream>
#include "mingw.thread.h"
#include<Windows.h>
#include<ctime>
namespace fightFunction{
    std::string didTheUserType = "NO";
    std::string enemyLogic = "NULL";
    std::string playerLogic =" NULL";
    std::string enemyPreviousLogic = "NULL";
    std::string playerPreviousLogic = "NULL";
    bool doProceed = false;
    bool didFunctionQuit = false;
    void countDown(){
        int time = std::time(NULL);
        // std::cout<<time<<"   "<<std::time(NULL)<<std::endl;
        int plusFive = time + 5;
        int plusOne = time + 1;
        int plusTwo = time + 2;
        int plusThree = time + 3;
        int plusFour = time + 4;
        // std::cout<<plusFive<<std::endl;
        while(time != plusFive && fightFunction::doProceed !=true){
            if(fightFunction::didTheUserType=="attack"||fightFunction::didTheUserType == "defend"||fightFunction::didTheUserType == "jump"){
                fightFunction::doProceed = true;
                fightFunction::playerLogic = didTheUserType;
            }
            else if(fightFunction::didTheUserType != "NO"){
                std::cout<<"nope!try again"<<std::endl;
                fightFunction::didTheUserType = "NO";
            }
            time = std::time(NULL);
        }
        // std::cout<<"this thread has been closed"<<std::endl;
        fightFunction::didFunctionQuit = true;
    }
    void reset(){
        fightFunction::didFunctionQuit = false;
        fightFunction::didTheUserType="NO";
        fightFunction::doProceed = false;
        fightFunction::didFunctionQuit = false;
    }
} // namespace fightFunction
class Fighting{
    private:
    void generateEnemyLogic(){
        srand(time(NULL));
        int dummy;
        dummy = rand()%3;
        if(dummy==0){
            fightFunction::enemyLogic=="attack";
        }else if(dummy==1){
            fightFunction::enemyLogic=="defend";
        }else{
            fightFunction::enemyLogic=="jump";
        }
    }
    std::string enemyName;//I don't know if need these two or not.Anyway , i included this here, you can remove it if you dont want to tho.
    void getEvent(){
        std::thread th( fightFunction::countDown);
        while(fightFunction::didFunctionQuit == false && fightFunction::doProceed != true){
            // std::cout<<"intput is going to be given"<<std::endl;
            std::cin>>fightFunction::didTheUserType;
            // std::cout<<"input has been given"<<std::endl;
        }
        th.join();
        fightFunction::playerLogic=fightFunction::didTheUserType;
        fightFunction::reset();
    }
    public:
    //startBattle works both as a constructor and as a function.
    void startBattle(std::string ename/*enemyName*/,int enemyDefendStat/*in percentage*/=50,int playerBaseDamage=10,int enemyBaseDamage=10,int enemyHealth=100,bool isPlayerFirst = true){
        int PBD = playerBaseDamage;
        int EBD = enemyBaseDamage;
        this->enemyName=ename;
        //printing instructions for the battle
        std::cout<<"\t1:Type `attack` to attack the enemy."<<std::endl<<"\t2:Type `defend` to brace yourself for impact(you will take damage but extremely lower than usual.defending yourself will increase the attack power if you `attack` right after `defend`)"<<std::endl;
        std::cout<<"\t3:Type `jump` to jump backward to completely miss the enemy attack, however if you type `attack` right after `jump` your damage output will be lower"<<std::endl;
        if(isPlayerFirst == true){
            std::cout<<"The "<<this->enemyName<<" is infront for you, You : "<<std::endl;
            this->getEvent();
            if(fightFunction::playerLogic=="attack"){
                std::cout<<"You attacked "<<this->enemyName<<" and inflicted "<<playerBaseDamage*(enemyDefendStat/100);
                enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
            }else if(fightFunction::playerLogic=="defend"){
                std::cout<<"you proceeded with caution and the enemy saw you."<<std::endl;
            }else if(fightFunction::playerLogic=="jump"){
                std::cout<<"you stepped back a bit,the enemy saw you"<<std::endl;
            }
            else{
                std::cout<<"You stared at him, both drawed swords and assumed battle positions"<<std::endl;
            }
        }else{
            this->generateEnemyLogic();
            std::cout<<"the enemy is about to "<<fightFunction::enemyLogic<<"   you: "<<std::endl;
            this->getEvent();
            if(fightFunction::playerLogic=="attack"){
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<"you inflicted "<< playerBaseDamage*(enemyDefendStat/100) <<std::endl;
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                    enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" defended";
                    std::cout<<"you inflicted "<<(playerBaseDamage*(enemyDefendStat/100))/4;
                    fightFunction::enemyPreviousLogic=="defend";
                }else{
                    std::cout<<this->enemyName<<" jumped back, you did no damage."<<std::endl;
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }
            }else if(fightFunction::playerLogic=="defend"){
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                std::cout<<"you defended"<<std::endl;
                std::cout<<"your next attack will be 3/4th stronger!"<<std::endl;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(enemyBaseDamage*(playerDefendStat/100))/4;
                    playerHealth = playerHealth - (enemyBaseDamage*(playerDefendStat/100))/4 ;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }else{
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }
            }else if(fightFunction::playerLogic=="jump"){
                std::cout<<"you jumped!"<<std::endl;
                std::cout<<"your next attack will be 1/4th of the original!"<<std::endl;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
            }else{
                std::cout<<"you failed to move in time!"<<std::endl;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                }
                fightFunction::playerPreviousLogic = "none";
                fightFunction::enemyPreviousLogic = fightFunction::enemyLogic;
            }
        }
        while(playerHealth>=0 || enemyHealth>=0){
            this->generateEnemyLogic();
            //continue battle here
            std::cout<<this->enemyName<<" is about to "<<fightFunction::enemyLogic<<std::endl;
            this->getEvent();
            if(fightFunction::playerPreviousLogic=="jump"){
                PBD = PBD/4;
            }else if(fightFunction::playerPreviousLogic=="defend"){
                PBD=PBD + (PBD*3/4);
            }
            if(fightFunction::enemyPreviousLogic=="jump"){
                EBD=EBD/4;
            }else if(fightFunction::enemyPreviousLogic=="defend"){
                EBD=EBD+(EBD*3/4);
            }
            if(fightFunction::playerLogic=="attack"){
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<"You inflicted "<<(PBD*enemyDefendStat/100)<<" on "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*playerDefendStat/100)<<" on YOU"<<std::endl;
                    enemyHealth=enemyHealth-(PBD*enemyDefendStat/100);
                    playerHealth=playerHealth-(EBD*playerDefendStat/100);
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"you inflicted "<<((PBD*enemyDefendStat/100)/4)<<std::endl;
                    enemyHealth=enemyHealth-((PBD*enemyDefendStat/100)/4);
                }else if(fightFunction::enemyLogic=="jump"){
                    std::cout<<"you did no damage to "<<this->enemyName<<std::endl;
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else if(fightFunction::playerLogic=="defend"){
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(playerDefendStat/100))/4<<" on you"<<std::endl;
                    playerHealth=playerHealth-(EBD*(playerDefendStat/100))/4;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"both defended, really!"<<std::endl;
                }else if(fightFunction::enemyLogic=="jump"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else if(fightFunction::playerLogic=="jump"){
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<"you evaded the attack!"<<std::endl;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                }else if(fightFunction::enemyLogic=="jump"){
                    std::cout<<this->enemyName<<" and you both finished playing dance floor arcade machine,it was a tie"<<std::endl;
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else{
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<EBD*playerDefendStat/100<<" on you while you were staring at him"<<std::endl;
                }else{
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                }
                fightFunction::playerPreviousLogic="NULL";
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }
        }
    }
};
int main(){
    Fighting f;
    f.startBattle("nirmalie");
}
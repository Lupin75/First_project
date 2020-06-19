//  g++ -std=c++17 fighting.cpp -D_WIN32_WINNT=0x0A00
/*

    okay, new bug: the very first attack is not getting considered for no reason

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
// #include"global.hpp"
#include<iostream>
#include<SFML/System.hpp>
#include<Windows.h>
#include<ctime>
std::string temporaryInput="NO";
namespace fightFunction{
    std::string didTheUserType = "NO";
    std::string enemyLogic = "NULL";
    std::string playerLogic = "NULL";
    std::string enemyPreviousLogic = "NULL";
    std::string playerPreviousLogic = "NULL";
    bool didGetEventProceed = false;
    bool doProceed = false;
    bool didFunctionQuit = false;
    void countDown(){
        int time = std::time(NULL);
        // std::cout<<time<<"   "<<std::time(NULL)<<std::endl;
        int plusFive = time + 5;
        // std::cout<<plusFive<<std::endl;
        while(time != plusFive && fightFunction::doProceed !=true){
            if(fightFunction::didGetEventProceed != true){
                continue;
            }else{
                fightFunction::didTheUserType=temporaryInput;
                if(fightFunction::didTheUserType== "attack" ||fightFunction::didTheUserType == "defend"||fightFunction::didTheUserType == "jump"){
                    fightFunction::doProceed = true;
                    fightFunction::playerLogic = didTheUserType;
                }
                else if(fightFunction::didTheUserType != "NO" && fightFunction::didTheUserType!="attack" && fightFunction::didTheUserType != "defend" && fightFunction::didTheUserType != "jump"){
                    std::cout<<"nope!try again"<<std::endl;
                    fightFunction::didTheUserType = "NO";
                    temporaryInput="NO";
                }
                time = std::time(NULL);
                fightFunction::didGetEventProceed = false;
            }
        }
        // std::cout<<"this thread has been closed"<<std::endl;
        fightFunction::didFunctionQuit = true;
    }
    void reset(){
        fightFunction::didFunctionQuit = false;
        fightFunction::didTheUserType = "NO";
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
            fightFunction::enemyLogic="attack";
        }else if(dummy==1){
            fightFunction::enemyLogic="defend";
        }else{
            fightFunction::enemyLogic="jump";
        }
    }
    std::string enemyName;//I don't know if need these two or not.Anyway , i included this here, you can remove it if you dont want to tho.
    void getEvent(){
        sf::Thread thread(&fightFunction::countDown);
        thread.launch();
        while(fightFunction::didFunctionQuit == false){
            // std::cout<<"intput is going to be given"<<std::endl;
            if(fightFunction::didGetEventProceed == false){
                std::cin>>temporaryInput;
                fightFunction::didGetEventProceed = true;
            }else{
                continue;
            }
            // std::cout<<"input has been given"<<std::endl;
        }
        thread.wait();
        if(fightFunction::doProceed!=true){
            std::cout<<"you failed to move in time"<<std::endl;
        }else{
            fightFunction::playerLogic=fightFunction::didTheUserType;
        }
        fightFunction::reset();
    }
    public:
    //startBattle works both as a constructor and as a function.ename is enemy name. eH is enemy health
    bool startBattle(std::string ename/*enemyName*/,int enemyDefendStat/*in percentage*/=50,int playerBaseDamage=10,int enemyBaseDamage=10,int eH=10,int playerHealInPercentage = 50,int enemyhealInPercentage = 50,bool isPlayerFirst = true){
        int enemyHealth = eH;
        int PBD = playerBaseDamage;
        int EBD = enemyBaseDamage;
        this->enemyName=ename;
        int enemyMaxHealth = enemyHealth;
        //printing instructions for the battle
        std::cout<<"INSTRUCTIONS"<<std::endl;
        std::cout<<"\t1:Type `attack` to attack the enemy."<<std::endl<<"\t2:Type `defend` to brace yourself for impact(you will take damage but 1/4th than usual.defending yourself will increase the attack power if you `attack` right after `defend`)"<<std::endl;
        std::cout<<"\t3:Type `jump` to jump backward to completely miss the enemy attack and heal yourself, however if you type `attack` right after `jump` your damage output will be lower"<<std::endl;
        system("pause");
        std::cout<<"the battle has begun!"<<std::endl;
        if(isPlayerFirst == true){
            std::cout<<this->enemyName<<" is infront for you"<<std::endl<<"YOU:"<<std::endl;
            this->getEvent();
            if(fightFunction::playerLogic == "attack" ){
                std::cout<<"You attacked "<<this->enemyName<<" and inflicted "<<playerBaseDamage*(enemyDefendStat/100)<<" damage on "<<this->enemyName<<std::endl;
                enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
            }else if(fightFunction::playerLogic=="defend"){
                std::cout<<"you proceeded with caution and the enemy saw you."<<std::endl;
            }else if(fightFunction::playerLogic== "jump" ){
                std::cout<<"you stepped back a bit,the enemy saw you"<<std::endl;
                playerHealth = playerHealth + (playerHealth*playerHealInPercentage/100);
            }
            else{
                std::cout<<"You stared at him, both drawed swords and assumed battle positions"<<std::endl;
            }
        }else{
            this->generateEnemyLogic();
            std::cout<<"The enemy is about to "<<fightFunction::enemyLogic<<std::endl<<"you:"<<std::endl;
            this->getEvent();
            if(fightFunction::playerLogic == "attack"){
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<"you inflicted "<< playerBaseDamage*(enemyDefendStat/100) <<" damage to "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                    enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" defended";
                    std::cout<<"you inflicted "<<(playerBaseDamage*(enemyDefendStat/100))/4<<" on the "<<this->enemyName<<std::endl;
                    fightFunction::enemyPreviousLogic=="defend";
                }else{
                    std::cout<<this->enemyName<<" jumped back, you did no damage."<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                    }
                }
            }else if(fightFunction::playerLogic=="defend"){
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                std::cout<<"you defended"<<std::endl;
                std::cout<<"your next attack will be 3/4th stronger!"<<std::endl;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(enemyBaseDamage*(playerDefendStat/100))/4<<" damage on you"<<std::endl;
                    playerHealth = playerHealth - (enemyBaseDamage*(playerDefendStat/100))/4 ;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                }else{
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                    }
                }
            }else if(fightFunction::playerLogic == "jump"){
                std::cout<<"you jumped!"<<std::endl;
                std::cout<<"you got heled"<<std::endl;
                playerHealth = playerHealth + (playerHealth*playerHealInPercentage/100);
                std::cout<<"your next attack will be 1/4th of the original!"<<std::endl;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                if(fightFunction::enemyLogic == "jump"){
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth=enemyHealth+(enemyHealth*enemyhealInPercentage/100);
                    }
                }
            }else{
                std::cout<<"you failed to move in time!"<<std::endl;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                }else if(fightFunction::enemyLogic == "jump"){
                    if(enemyHealth < enemyMaxHealth){
                        enemyHealth=enemyHealth+(enemyHealth*enemyhealInPercentage/100);
                    }
                }
                fightFunction::playerPreviousLogic = "none";
                fightFunction::enemyPreviousLogic = fightFunction::enemyLogic;
            }
        }
        std::cout<<"YOU HEALTH IS "<<playerHealth<<std::endl;
        std::cout<<this->enemyName<<" HEALTH IS "<<enemyHealth<<std::endl;
        system("pause");
        while(playerHealth >=0 && enemyHealth >= 0 ) {
            std::cout<<"YOU HEALTH IS "<<playerHealth<<std::endl;
            std::cout<<this->enemyName<<" HEALTH IS "<<enemyHealth<<std::endl;
            system("pause");
            this->generateEnemyLogic();
            //continue battle here
            std::cout<<this->enemyName<<" is about to "<<fightFunction::enemyLogic<<std::endl;
            std::cout<<"YOU: "<<std::endl;
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
                    std::cout<<"You inflicted "<<(PBD*enemyDefendStat/100)<<" damage on "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*playerDefendStat/100)<<" damage on YOU"<<std::endl;
                    enemyHealth = enemyHealth - (PBD*enemyDefendStat/100);
                    std::cout<<enemyHealth<<std::endl;
                    playerHealth = playerHealth - (EBD*playerDefendStat/100);
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"you inflicted "<<((PBD*enemyDefendStat/100)/4)<<" damage on "<<this->enemyName<<std::endl;
                    enemyHealth = enemyHealth - ((PBD*enemyDefendStat/100)/4);
                    std::cout<<enemyHealth<<std::endl;
                }else if(fightFunction::enemyLogic=="jump"){
                    std::cout<<"you did no damage to "<<this->enemyName<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth+(enemyHealth*enemyhealInPercentage/100);
                    }
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else if(fightFunction::playerLogic=="defend"){
                std::cout<<"you defended"<<std::endl;
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(playerDefendStat/100))/4<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(EBD*(playerDefendStat/100))/4;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"both defended, really!"<<std::endl;
                }else if(fightFunction::enemyLogic=="jump"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth+(enemyHealth*enemyhealInPercentage/100);
                    }
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else if(fightFunction::playerLogic=="jump"){
                std::cout<<"you jumped"<<std::endl;
                playerHealth = playerHealth + (playerHealth*playerHealInPercentage/100);
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<"you evaded the attack!"<<std::endl;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                }else if(fightFunction::enemyLogic=="jump"){
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth + (enemyHealth*enemyhealInPercentage/100);
                    }
                    std::cout<<this->enemyName<<" and you both finished playing dance floor arcade machine,it was a tie"<<std::endl;
                }
                fightFunction::playerPreviousLogic=fightFunction::playerLogic;
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }else{
                if(fightFunction::enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<EBD*playerDefendStat/100<<" on you while you were staring at him"<<std::endl;
                }else if(fightFunction::enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                }else{
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth=enemyHealth+(enemyHealth*enemyhealInPercentage/100);
                    }
                }
                fightFunction::playerPreviousLogic="NULL";
                fightFunction::enemyPreviousLogic=fightFunction::enemyLogic;
            }
        }
        if(playerHealth>0 && enemyHealth <= 0){
            return true;
        }else{
            return false;
        }
    }
};
// int main(){
//     Fighting f;
//     if(!f.startBattle("nirmalie")){
//         std::cout<<"you died!"<<std::endl;
//     }else{
//         std::cout<<"success!"<<std::endl;
//     }
// }
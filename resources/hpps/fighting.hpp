#ifndef FIGHTING_HPP
#define FIGHTING_HPP
int playerHealth = 100;//remove this and include global.hpp
int playerDefendStat = 50;
// #include"global.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <ctime>

class Fighting{
    private:
    std::string enemyName;
    std::string input;
    std::string enemyLogic = "NULL";
    std::string playerLogic = "NULL";
    std::string enemyPreviousLogic = "NULL";
    std::string playerPreviousLogic = "NULL";

    void setEnemyLogic(){
        srand(time(NULL));
        int dummy;
        dummy = rand()%3;
        if(dummy==0){
            this->enemyLogic="attack";
        }else if(dummy==1){
            this->enemyLogic="defend";
        }else{
            this->enemyLogic="jump";
        }
    }
    void setPlayerLogic(){
        sf::Music music;
        music.openFromFile("resources/audio/clock-ticking.ogg");
        music.setVolume(15);
        music.play();
        sf::Clock timer;
        while(timer.getElapsedTime().asSeconds()<=5 ) {
            std::cout<<"ENTER PLAYER MOVE WITH IN 5 SECONDS"<<std::endl;
            std::cin>>this->input;
            if(timer.getElapsedTime().asSeconds()<=5) {
                if(this->input == "jump") {
                    music.stop();
                    this->playerLogic = this->input;
                    break;
                } else if(this->input == "attack"){
                    music.stop();
                    this->playerLogic = this->input;
                    break;
                } else if(this->input == "defend"){
                    music.stop();
                    this->playerLogic = this->input;
                    break;
                } else {
                    std::cout<<"incorrect input given"<<std::endl;
                }
            } else {
                music.stop();
                break;
            }
        }
    }   

    public:
    //startBattle works both as a constructor and as a function.ename is enemy name. eH is enemy health
    bool startBattle(std::string ename/*enemyName*/,int enemyDefendStat/*in percentage*/=50,int playerBaseDamage=10,int enemyBaseDamage=10,int enemyHealth=10,bool isPlayerFirst = true){
        int PBD = playerBaseDamage;
        int EBD = enemyBaseDamage;
        this->enemyName=ename;
        int enemyMaxHealth = enemyHealth;
        int playerMaxHealth = playerHealth;
        //printing instructions for the battle
        std::cout<<"INSTRUCTIONS"<<std::endl;
        std::cout<<"\t1:Type `attack` to attack the enemy."<<std::endl<<"\t2:Type `defend` to brace yourself for impact(you will take damage but 1/4th than usual.defending yourself will increase the attack power if you `attack` right after `defend`)"<<std::endl;
        std::cout<<"\t3:Type `jump` to jump backward to completely miss the enemy attack and heal yourself, however if you type `attack` right after `jump` your damage output will be lower"<<std::endl;
        system("pause");
        std::cout<<"the battle has begun!"<<std::endl;
        if(isPlayerFirst == true){
            std::cout<<this->enemyName<<" is infront for you"<<std::endl<<"YOU:"<<std::endl;
            this->setPlayerLogic();
            if(this->playerLogic == "attack" ){
                std::cout<<"You attacked "<<this->enemyName<<" and inflicted "<<playerBaseDamage*(enemyDefendStat/100)<<" damage on "<<this->enemyName<<std::endl;
                enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
            }else if(this->playerLogic=="defend"){
                std::cout<<"you proceeded with caution and the enemy saw you."<<std::endl;
            }else if(this->playerLogic== "jump" ){
                std::cout<<"you stepped back a bit,the enemy saw you"<<std::endl;
                if(playerHealth < playerMaxHealth){
                    playerHealth = playerHealth + ( playerMaxHealth / 20 );
                }else{
                    std::cout<<"player is full health"<<std::endl;
                }
            }
            else{
                std::cout<<"You stared at him, both drawed swords and assumed battle positions"<<std::endl;
            }
        }else{
            this->setEnemyLogic();
            std::cout<<"The enemy is about to "<<this->enemyLogic<<std::endl<<"you:"<<std::endl;
            this->setPlayerLogic();
            if(this->playerLogic == "attack"){
                this->playerPreviousLogic =this->playerLogic;
                if(this->enemyLogic=="attack"){
                    std::cout<<"you inflicted "<< playerBaseDamage*(enemyDefendStat/100) <<" damage to "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                    enemyHealth=enemyHealth-(playerBaseDamage*(enemyDefendStat/100));
                    this->enemyPreviousLogic =this->enemyLogic;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" defended";
                    std::cout<<"you inflicted "<<(playerBaseDamage*(enemyDefendStat/100))/4<<" on the "<<this->enemyName<<std::endl;
                    this->enemyPreviousLogic =="defend";
                }else{
                    std::cout<<this->enemyName<<" jumped back, you did no damage."<<std::endl;
                    // if(enemyHealth<enemyMaxHealth){
                    //     this->enemyPreviousLogic =this->enemyLogic;
                    // }
                    if( enemyHealth < enemyMaxHealth ){
                        enemyHealth = enemyHealth + ( enemyMaxHealth / 20 );
                    }
                }
            }else if(this->playerLogic=="defend"){
                this->playerPreviousLogic =this->playerLogic;
                std::cout<<"you defended"<<std::endl;
                std::cout<<"your next attack will be 3/4th stronger!"<<std::endl;
                if(this->enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(enemyBaseDamage*(playerDefendStat/100))/4<<" damage on you"<<std::endl;
                    playerHealth = playerHealth - (enemyBaseDamage*(playerDefendStat/100))/4 ;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    this->enemyPreviousLogic =this->enemyLogic;
                }else{
                    std::cout<<this->enemyName<<" did nothing"<<std::endl;
                    // if(enemyHealth<enemyMaxHealth){
                    //     this->enemyPreviousLogic =this->enemyLogic;
                    // }
                    if( enemyHealth < enemyMaxHealth ){
                        enemyHealth = enemyHealth + ( enemyMaxHealth / 20 );
                    }
                }
            }else if(this->playerLogic == "jump"){
                std::cout<<"you jumped!"<<std::endl;
                std::cout<<"you got healed"<<std::endl;
                if(playerHealth < playerMaxHealth){
                    playerHealth = playerHealth + ( playerMaxHealth / 20 );
                }else{
                    std::cout<<"player is full health"<<std::endl;
                }
                std::cout<<"your next attack will be 1/4th of the original!"<<std::endl;
                this->enemyPreviousLogic =this->enemyLogic;
                this->playerPreviousLogic =this->playerLogic;
                if(this->enemyLogic == "jump"){
                    if( enemyHealth < enemyMaxHealth ){
                        enemyHealth = enemyHealth + ( enemyMaxHealth / 20 );
                    }
                }
            }else{
                std::cout<<"you failed to move in time!"<<std::endl;
                this->playerLogic = "none";
                if(this->enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" infilcted "<< enemyBaseDamage*(playerDefendStat/100)<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(enemyBaseDamage*(playerDefendStat/100));
                }else if(this->enemyLogic == "jump"){
                    if( enemyHealth < enemyMaxHealth ){
                        enemyHealth = enemyHealth + ( enemyMaxHealth / 20 );
                    }
                }
                this->playerPreviousLogic  = "none";
                this->enemyPreviousLogic  = this->enemyLogic;
            }
        }
        this->enemyPreviousLogic = this->enemyLogic;
        this->playerPreviousLogic = this->playerLogic;
        while(playerHealth >=0 && enemyHealth >= 0 ) {
            std::cout<<"YOU HEALTH IS "<<playerHealth<<std::endl;
            std::cout<<this->enemyName<<" HEALTH IS "<<enemyHealth<<std::endl;
            system("pause");
            this->setEnemyLogic();
            std::cout<<this->enemyName<<" is about to "<<this->enemyLogic<<std::endl;
            std::cout<<"YOU: "<<std::endl;
            this->setPlayerLogic();
            if(this->playerPreviousLogic =="jump"){
                PBD = PBD/4;
            }else if(this->playerPreviousLogic =="defend"){
                PBD=PBD + (PBD*3/4);
            }
            if(this->enemyPreviousLogic =="jump"){
                EBD=EBD/4;
            }else if(this->enemyPreviousLogic =="defend"){
                EBD=EBD+(EBD*3/4);
            }
            if(this->playerLogic=="attack"){
                if(this->enemyLogic=="attack"){
                    std::cout<<"You inflicted "<<(PBD*enemyDefendStat/100)<<" damage on "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*playerDefendStat/100)<<" damage on YOU"<<std::endl;
                    enemyHealth = enemyHealth - (PBD*enemyDefendStat/100);
                    std::cout<<enemyHealth<<std::endl;
                    playerHealth = playerHealth - (EBD*playerDefendStat/100);
                }else if(this->enemyLogic=="defend"){
                    std::cout<<"you inflicted "<<((PBD*enemyDefendStat/100)/4)<<" damage on "<<this->enemyName<<std::endl;
                    enemyHealth = enemyHealth - ((PBD*enemyDefendStat/100)/4);
                    std::cout<<enemyHealth<<std::endl;
                }else if(this->enemyLogic=="jump"){
                    std::cout<<"you did no damage to "<<this->enemyName<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth+(enemyMaxHealth/20);
                    }
                }
                this->playerPreviousLogic =this->playerLogic;
                this->enemyPreviousLogic =this->enemyLogic;
            }else if(this->playerLogic=="defend"){
                std::cout<<"you defended"<<std::endl;
                if(this->enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(playerDefendStat/100))/4<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(EBD*(playerDefendStat/100))/4;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<"both defended, really!"<<std::endl;
                }else if(this->enemyLogic=="jump"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth+(enemyMaxHealth/20);
                    }
                }
                this->playerPreviousLogic =this->playerLogic;
                this->enemyPreviousLogic =this->enemyLogic;
            }else if(this->playerLogic=="jump"){
                std::cout<<"you jumped"<<std::endl;
                playerHealth = playerHealth + (playerMaxHealth/20);
                if(this->enemyLogic=="attack"){
                    std::cout<<"you evaded the attack!"<<std::endl;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<"nothing happened, it just felt like 2 magikarp fighting eachother(-_-)"<<std::endl;
                }else if(this->enemyLogic=="jump"){
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth + (enemyMaxHealth/20);
                    }
                    std::cout<<this->enemyName<<" and you both finished playing dance floor arcade machine,it was a tie"<<std::endl;
                }
                this->playerPreviousLogic =this->playerLogic;
                this->enemyPreviousLogic =this->enemyLogic;
            }else{
                if(this->enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<EBD*playerDefendStat/100<<" on you while you were staring at him"<<std::endl;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                }else{
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth=enemyHealth+(enemyMaxHealth/20);
                    }
                }
                this->playerPreviousLogic ="NULL";
                this->enemyPreviousLogic =this->enemyLogic;
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
#endif
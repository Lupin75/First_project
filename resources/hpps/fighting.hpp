#ifndef FIGHTING_HPP
#define FIGHTING_HPP
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Fighting{
    private:
    std::string enemyName;
    std::string enemyLogic = "NULL";
    std::string playerLogic = "NULL";
    std::string enemyPreviousLogic = "NULL";
    std::string playerPreviousLogic = "NULL";

    string toSmall(string large)
    {
        for (int i = 0; i < large.size(); i++){
            if (isalpha(large[i]) != 0){
                if (isupper(large[i]) != 0){
                    large[i] = tolower(large[i]);
                }
            }
        }
        return large;
    }

    void setEnemyLogic(){
        srand(time(NULL));
        if(this->enemyPreviousLogic == "jump"){
            int dummy;
            dummy = rand()%2;
            if(dummy == 1){
                this->enemyLogic = "defend";
            }else{
                int d2;
                d2 = rand()%2;
                if(d2 == 0){
                    this->enemyLogic = "attack";
                }else{
                    this->enemyLogic = "jump";
                }
            }
        }else if(this->enemyPreviousLogic == "defend"){
            int d;
            d = rand()%5;
            if(d == 0 || d == 1){
                this->enemyLogic = "attack";
            }else if(d == 2 || d == 3){
                this->enemyLogic = "defend";
            }else{
                this->enemyLogic = "jump";
            }
        }else{
            int da;
            da= rand()%4;
            if(da == 0 || da == 1){
                this->enemyLogic = "attack";
            }else if(da == 2){
                this->enemyLogic = "defend";
            }else{
                this->enemyLogic = "jump";
            }
        }
    }

    void reset(){
        std::string enemyLogic = "NULL";
        std::string playerLogic = "NULL";
        std::string enemyPreviousLogic = "NULL";
        std::string playerPreviousLogic = "NULL";
    }
    void setPlayerLogic(){
        sf::Music music;
        music.openFromFile("resources/audio/clock-ticking.ogg");
        music.setVolume(15);
        music.play();
        std::string input;
        sf::Clock timer;
        while(timer.getElapsedTime().asSeconds()<=8 ) {
            std::cout<<"ENTER PLAYER'S MOVE WITH IN 8 SECONDS"<<std::endl;
            std::cin>>input;
            input = this->toSmall(input);
            if(timer.getElapsedTime().asSeconds()<=8) {
                if(input == "jump" || input == "attack" || input == "defend") {
                    music.stop();
                    this->playerLogic = input;
                    break;
                } else {
                    std::cout<<"incorrect input given"<<std::endl;
                }
            } else {
                std::cout<<"you failed to move in time"<<std::endl;
                music.stop();
                break;
            }
        }
    }   

    public:
    //startBattle works both as a constructor and as a function.ename is enemy name. eH is enemy health
    //Parameters - enemyname ,enemy defense stat, player base damage, enemy base damage, enemy health , isplayer first
    bool startBattle(std::string ename/*enemyName*/,int enemyDefendStat/*in percentage*/=50,int playerBaseDamage=10,int enemyBaseDamage=10,int enemyHealth=10,bool isPlayerFirst = true){
        int playerHealth = 100;
        int playerDefendStat = 50;
        int PBD = playerBaseDamage;
        int EBD = enemyBaseDamage;
        this->enemyName=ename;
        int enemyMaxHealth = enemyHealth;
        int playerMaxHealth = playerHealth;
        //printing instructions for the battle
        wrap("INSTRUCTIONS");
        wrap("\t1:Type `attack` to attack the enemy.");
        wrap("\t2:Type `defend` to brace yourself for impact(you will take damage but 1/4th than usual.defending yourself will increase the attack power if you `attack` right after `defend`)");
        wrap("\t3:Type `jump` to jump backward to completely miss the enemy attack and heal yourself, however if you type `attack` right after `jump` your damage output will be lower");
        cls();
        if(findOs()=="Windows 32-bit")
            setcolor(true);
        std::cout<<"the battle has begun!"<<std::endl;
        if(isPlayerFirst == true){
            std::cout<<this->enemyName<<" is infront for you"<<std::endl<<"\tYOU:"<<std::endl;
            this->setPlayerLogic();
            if(this->playerLogic == "attack" ){
                std::cout<<"You attacked "<<this->enemyName<<" and inflicted "<<(PBD*(1-(enemyDefendStat/100)))<<" damage on "<<this->enemyName<<std::endl;
                enemyHealth = enemyHealth - (PBD*(1-(enemyDefendStat/100)));
            }else if(this->playerLogic == "defend" ){
                std::cout<<"you proceeded with caution and the enemy saw you."<<std::endl;
            }else if(this->playerLogic == "jump" ){
                std::cout<<"you stepped back a bit,the enemy saw you"<<std::endl;
            }
            else{
                std::cout<<"You stared at him, both drawed swords and assumed battle positions"<<std::endl;
            }
        }
        for(int i=0; i<5;i++ ){
            std::cout<<std::endl;
        }
        while(playerHealth >0 && enemyHealth > 0 ) {
            PBD = playerBaseDamage;
            EBD = enemyBaseDamage;
            this->setEnemyLogic();
            std::cout<<this->enemyName<<" is about to "<<this->enemyLogic<<std::endl;
            this->setPlayerLogic();
            if(this->playerPreviousLogic == "jump"){
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
                    std::cout<<"You inflicted "<<(PBD*(1-(enemyDefendStat/100)))<<" damage on "<<this->enemyName<<std::endl;
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(1-(playerDefendStat/100)))<<" damage on YOU"<<std::endl;
                    enemyHealth = enemyHealth - (PBD*(1-(enemyDefendStat/100)));
                    playerHealth = playerHealth - (EBD*(1-(playerDefendStat/100)));
                }else if(this->enemyLogic=="defend"){
                    std::cout<<"you inflicted "<<((PBD*(1-(enemyDefendStat/100)))/4)<<" damage on "<<this->enemyName<<std::endl;
                    enemyHealth = enemyHealth - ((PBD*(1-(enemyDefendStat/100)))/4);
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
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(1-(playerDefendStat/100))/4)<<" damage on you"<<std::endl;
                    playerHealth=playerHealth-(EBD*(1-(playerDefendStat/100))/4);
                }else if(this->enemyLogic=="defend"){
                    std::cout<<"both defended, really!"<<std::endl;
                }else if(this->enemyLogic=="jump"){
                    std::cout<<"nothing happened."<<std::endl;
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
                    std::cout<<"nothing happened."<<std::endl;
                }else if(this->enemyLogic=="jump"){
                    if(enemyHealth<enemyMaxHealth){
                        enemyHealth = enemyHealth + (enemyMaxHealth/20);
                    }
                    std::cout<<this->enemyName<<" and you both finished jumping around."<<std::endl;
                }
                this->playerPreviousLogic =this->playerLogic;
                this->enemyPreviousLogic =this->enemyLogic;
            }else{
                if(this->enemyLogic=="attack"){
                    std::cout<<this->enemyName<<" inflicted "<<(EBD*(1-(playerDefendStat/100)))<<" on you while you were staring at him"<<std::endl;
                    playerHealth = playerHealth - (EBD*(1-(playerDefendStat/100))) ;
                }else if(this->enemyLogic=="defend"){
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                }else{
                    std::cout<<this->enemyName<<" did nothing, due to your insane luck"<<std::endl;
                    if( enemyHealth< enemyMaxHealth ){
                        enemyHealth = enemyHealth + ( enemyMaxHealth / 20 );
                    }
                }
                this->playerPreviousLogic = "NULL";
                this->enemyPreviousLogic = this->enemyLogic;
            }
            for(int i=0; i<5;i++ ){
                std::cout<<std::endl;
            }
            std::cout<<playerName<<"'s health is ";
            if(playerHealth < 0){
                std::cout<<0<<std::endl;
            }else{
                std::cout<<playerHealth<<std::endl;
            }
            std::cout<<this->enemyName<<"'s health is ";
            if(enemyHealth < 0){
                std::cout<<0<<std::endl;
            }else{
                std::cout<<enemyHealth<<std::endl;
            }
        }
        if(playerHealth>0 && enemyHealth <= 0){
            this->reset();
            return true;
        }else{
            this->reset();
            return false;
        }
    }
};

#endif

/*
#include "resources/hpps/fighting.hpp"
#include <iostream>
int main(){
    Fighting f;
    if(!f.startBattle("nirmalie")){
        std::cout<<"failed"<<std::endl;
    }else{
        std::cout<<"passed"<<std::endl;
    }
}
*/
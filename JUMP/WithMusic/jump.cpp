#include<iostream>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include"mingw.thread.h"
using namespace std;
int fiveSeconds = 5 ;
std::string typeJump = "heDidNotType";
bool doProceed = false;
bool didCountingFiveSecondsQuit = false;
int countingFiveSeconds(){
    sf::Music music;
    if(!music.openFromFile("clock-ticking.ogg")){
        std::cout<<"error! clock-ticking.ogg not found!"<<std::endl;
        return -1;
    }
    while(fiveSeconds !=-1 && doProceed != true){
        fiveSeconds--;
        music.play();
        Sleep(1000);
        music.stop();
        if(typeJump == "jump"){
            doProceed = true;
            std::cout<<"passed"<<std::endl;
        }else if(typeJump != "heDidNotType"){
            std::cout<<"nope!try again"<<std::endl;
            typeJump = "heDidNotType";
        }
    }
    didCountingFiveSecondsQuit = true;
    return 0;
}
int main(){
    std::thread counting(countingFiveSeconds);
    while(didCountingFiveSecondsQuit == false){
        std::cin>>typeJump;
        Sleep(1000);
    }
    counting.join();
    if(doProceed != true){
        std::cout<<"you failed"<<std::endl;
    }else{
        std::cout<<"you have passed"<<std::endl;
    }
    return 0;
}
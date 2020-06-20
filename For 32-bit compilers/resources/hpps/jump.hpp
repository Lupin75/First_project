#include<iostream>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<SFML/System.hpp>
using namespace std;
int fiveSeconds = 5 ;
std::string typeJump = "heDidNotType";
bool doProceed = false;
bool didCountingFiveSecondsQuit = false;
// namespace typingJump
namespace typingJump
{
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
} 
//Returns true if jumped in time else false
bool jumpFunction(){
    cout<<"Enter \"Jump\" in five seconds: "<<endl;
    sf::Thread thread(&typingJump::countingFiveSeconds);
    thread.launch();
    while(didCountingFiveSecondsQuit == false){
        std::cin>>typeJump;
        Sleep(1000);
    }
    thread.wait();
    if(doProceed != true){
        std::cout<<"you failed"<<std::endl;
        return false;
    }else{
        std::cout<<"you have passed"<<std::endl;
        return true;
    }
}
/*
int main(){
    cout<<"type jump within 5 seconds"<<endl;
    if(jumpFunction()==true){
        cout<<"passed"<<endl;
    }else{
        cout<<"failed"<<endl;
    }
}
*/
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
using namespace std;

// namespace typingJump
namespace typingJump{
    int fiveSeconds = 5 ;
    std::string typeJump = "heDidNotType";
    bool doProceed = false;
    bool didCountingFiveSecondsQuit = false;
    void reset(){
        fiveSeconds = 5 ;
        typeJump = "heDidNotType";
        doProceed = false;
        didCountingFiveSecondsQuit = false;
    }
    void countingFiveSeconds(){
        sf::Music music;
        if(!music.openFromFile("./resources/audio/clock-ticking.ogg")){
            std::cout<<"error! clock-ticking.ogg not found!"<<std::endl;
            goto x;
        }
        while(fiveSeconds !=-1 && doProceed != true){
            fiveSeconds--;
            music.play();
            sf::sleep(sf::milliseconds(1000));
            music.stop();
            if(typeJump == "jump"){
                doProceed = true;
            }else if(typeJump != "heDidNotType"){
                std::cout<<"nope!try again"<<std::endl;
                typeJump = "heDidNotType";
            }
        }
        x:
        didCountingFiveSecondsQuit = true;
    }
} 
//Returns true if jumped in time else false
bool jumpFunction(){
    cout<<"Enter \"Jump\" in 5 seconds: "<<endl;
    sf::Thread thread(&typingJump::countingFiveSeconds);
    thread.launch();
    while(typingJump::didCountingFiveSecondsQuit == false){
        std::cin>>typingJump::typeJump;
        sf::sleep(sf::milliseconds(1000));
    }
    thread.wait();
    if(typingJump::doProceed != true){
        std::cout<<"you failed"<<std::endl;
        typingJump::reset();
        return false;
    }else{
        std::cout<<"you passed"<<std::endl;
        typingJump::reset();
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
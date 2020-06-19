#include<SFML/System.hpp>
#include<iostream>
#include<Windows.h>
int fiveSeconds = 5 ;
std::string typeJump = "heDidNotType";
bool doProceed = false;
bool didFunctionQuit = false;
namespace typing{
    void countDown(){
        while(fiveSeconds != 0 && doProceed !=true){
            std::cout<<fiveSeconds<<std::endl;
            fiveSeconds--;
            Sleep(1000);
            if(typeJump == "jump"){
                doProceed = true;
            }else if(typeJump != "heDidNotType"){
                std::cout<<"nope!try again"<<std::endl;
                typeJump = "heDidNotType";
            }
            didFunctionQuit = true;
        }
    }
}
bool jumpFunction(){
    sf::Thread thread(&typing::countDown);
    thread.launch();
    while(didFunctionQuit == false){
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
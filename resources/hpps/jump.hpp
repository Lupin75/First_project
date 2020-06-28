#ifndef JUMP_HPP
#define JUMP_HPP
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
bool jumpFunction() {
    sf::Music music;
    music.openFromFile("resources/audio/clock-ticking.ogg");
    music.setVolume(15);
    music.play();
    sf::Clock timer;
    while(timer.getElapsedTime().asSeconds()<=5 ) {
        std::string input;
        std::cout<<"ENTER JUMP WITH IN 5 SECONDS"<<std::endl;
        std::cin>>input;
        if(timer.getElapsedTime().asSeconds()<=5) {
            if(input == "jump") {
                music.stop();
                return true;
            } else {
                std::cout<<"incorrect input given"<<std::endl;
            }
        } else {
            music.stop();
            return false;
        }
    }
}
#endif//JUMP_HPP
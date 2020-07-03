#ifndef INTRO_HPP
#define INTRO_HPP
#include<iostream>
#include"global.hpp"
int printTitle(){
    //cout -->title name here;
    std::cout<<"\t1: New Game"<<std::endl<<"\t2: Continue\n\t3: Exit"<<std::endl;
    int input;
    x:input = getInputAsInt(input);
    if(input == 1){
        remove("resources/txtFiles/custom.txt");
        remove("resources/txtFiles/progress.txt");
        remove("resources/txtFiles/playerName.txt");
    }else if(input == 3){
        _Exit(0);
    }else if(input != 2){
        std::cout<<"invalid input given , please try again!"<<std::endl;
        goto x;
    }
    return input;
}

#endif //INTRO_HPP
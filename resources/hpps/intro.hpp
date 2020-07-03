#ifndef INTRO_HPP
#define INTRO_HPP
#include<iostream>
#include"global.hpp"
void printTitle(){
    //cout -->title name here;
    std::cout<<"\t1: new game"<<std::endl<<"\t2: continue\n\t3: exit"<<std::endl;
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
}

#endif //INTRO_HPP
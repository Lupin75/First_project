#ifndef INTRO_HPP
#define INTRO_HPP
#include<iostream>
#include"global.hpp"
int printTitle(){
    //cout -->title name here;
    std::cout<<"\t1: New Game"<<std::endl<<"\t2: Continue\n\t3: Exit"<<std::endl;
    int input;
    Bar bar;
    x:input = getInputAsInt(input);
    if(input == 1){
        cout<<"Loading New Game\n";
        remove("resources/txtFiles/custom.txt");
        remove("resources/txtFiles/progress.txt");
        remove("resources/txtFiles/playerName.txt");
        bar.loadBar(30);
        cout<<endl;
        cls();
    }else if(input == 3){
        _Exit(0);
    }else if(input == 2){
        cout<<"Loading Last Checkpoint\n";
        bar.loadBar(30);
        cout<<endl;
        cls();
    }
    else
    {
        std::cout<<"invalid input given , please try again!"<<std::endl;
        goto x;
    }
    
    return input;
}

#endif //INTRO_HPP
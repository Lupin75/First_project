// #include<iostream>
// #include<thread>
// #include<chrono>
// #include<mutex>
// #include<condition_variable>
// using namespace std;
// condition_variable cv;
// condition_variable hello;
// string value;

// void read_value() {
//     cin >> value;
//     cv.notify_one();
// }

// int main()
// {
//     cout << "Please enter the input: ";
//     thread th(read_value);
//     mutex mtx;
//     unique_lock<mutex> lck(mtx);
//     while (cv.wait_for(lck, chrono::seconds(5)) == cv_status::timeout)
//     {
//         cout << "\nTime-Out: 5 second:";
//         cout << "\nPlease enter the input:";
//     }
//     cout << "You entered: " << value << '\n';
//     th.join();
//     return 0;
// }
#include<iostream>
#include "mingw.thread.h"
#include<Windows.h>
//g++ -std=c++17 jump.cpp -D_WIN32_WINNT=0x0A00
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
    std::thread th(typing::countDown);
    while(didFunctionQuit == false){
        std::cin>>typeJump;
        Sleep(1000);
    }
    th.join();
    if(doProceed != true){
        std::cout<<"you failed"<<std::endl;
        return false;
    }else{
        std::cout<<"you have passed"<<std::endl;
        return true;
    }
}
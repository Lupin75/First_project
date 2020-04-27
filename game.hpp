#pragma once
//-----------------------------------------------------------------------------------------------------------------
//inbuild header files
#include<iostream>
#include <fstream>
#include <ctype.h>
#include<Windows.h>
#include<math.h>
//------------------------------------------------------------------------------------------------------------------
#include"global.hpp"
using namespace std;

class Game{
    public:
    //Heads Up Display Details of Player
    void HUD(){
      Sleep(500);
      cout<<"Name: "<<playerName<<"   Health: "<<totalHealth<<"\nLevel: "<<level<<"\nXP: "<<currentXP<<"\nXP to Level: "<<XptoLevel<<endl;
      moving();
    }

    void combatHUD(){
      Sleep(500);
      system("cls");
      cout<<"Name:"<<playerName<< "   |    Enemy Name: "<<currentEnemyName<<"\nHealth: "<<totalHealth<<"   |   Enemy Health: "<<enemyHP<<"\nLevel: "<<level<<"   |   Monster Level: "<<enemyLevel<<endl;
 
    }

    void combat(){
      combatHUD();
      playerDamage=8*level/2;
      enemyAttack=6*enemyLevel/2;
      if(totalHealth>=1&&enemyHP>=1){
        cout<<"\n";
        cout<<"1. Attack\n";
        cout<<"2. Block\n";
        cout<<"3. Run!!\n";
        cout<<"\n";
        cin>>playerAttack;
        if(playerAttack==1){
          //Attack
          cout<<"Attacking..you did "<<playerDamage<<" to the "<<currentEnemyName<<endl;
          enemyHP=enemyHP-playerDamage;
          Sleep(1000);
          system("cls");
          if(enemyHP>=1){
            cout<<"\n";
            cout<<"Enemy is Attacking\n";
            totalHealth=totalHealth-enemyAttack;
            cout<<"You suffered "<<enemyAttack<<" hp "<<totalHealth<<endl;
            if(totalHealth<=0){
              totalHealth=0;
              system("cls");
              cout<<"You Died! \nYou were level: "<<level<<" You got killed by "<<currentEnemyName<<endl;
              Sleep(2000);
              exit(0);
            }
          }
            else if(enemyHP<=0){
              enemyHP=0;
              cout<<"\n";
              cout<<"You Defeated "<<currentEnemyName<<"You are rewarded with "<<enemyXP<<" XP\nWELL DONE!";
              if(level!=maxLevel){
                currentXP+=enemyXP;
                levelUp();
              }
              Sleep(1000);
              system("cls");
              HUD();
            }
            Sleep(1000);
            combat();
          }
        
        else if(playerAttack==2){
          //Block
          cout<<"Blocking\n";
          int i=rand()%100+1;
          if(i>=50){
            cout<<"You Blocked the incoming attack\n";
            heal=level*10/2;
            cout<<"You have been Healed for "<<heal<<endl;
            totalHealth+=heal;
            Sleep(1000);
            system("cls");
            combat();
          }
          else{
            cout<<"You failed to block the attack\n";
            totalHealth-=enemyAttack;
            cout<<"You were stabbed in the back for "<<enemyAttack<<" current hp "<<totalHealth<<endl;
            Sleep(1000);
            system("cls");
            combat();
          }
          }

        else if(playerAttack==3){
          //Run
          cout<<"You try to run\n";
          int x=rand()%100+1;
          if(x>=50){
            cout<<" You run away\n";
            Sleep(1000);
            system("cls");
            HUD();
          }
          else{
            cout<<"You failed to run away\n";
            cout<<"Enemy does a attack on you\n";
            totalHealth-=enemyAttack+10;
            cout<<"You suffered"<<enemyAttack+10<<"Your current Health is "<<totalHealth<<endl;
            Sleep(1000);
            combat();
          }

        }
        else{
          cout<<"Invalid Choice\n";
          Sleep(500);
          moving();
        }
      }
    }

    void moving()
    {
      int choice;
      cout<<"\n\n";
      cout<<"1. Move Forward\n";
      cout<<"2. Relax\n";
      cout<<"3. Move Backward\n";
      cout<<"\n";
      cin>>choice;
      if(choice==1){
        int temp=rand()%100+1;
        cout<<"You begin moving forward...\n"<<endl;
        if(temp>=50){
          // Encounter a enemy
          createEnemy();
          string tempName=enemyNames[rand()%currentEnemyNum];
          cout<<"A "<<tempName<<"Prepare to fight!!"<<endl;
          currentEnemyName=tempName;
          Sleep(1000);
          combat();
        }
        cout<<"You find nothing of interest\n";
        Sleep(1000);
        system("cls");
        HUD();
        moving();
      }
      else if(choice==2){
        cout<<"You want to setup camp for the evening\n";
        if(totalHealth<=90)
          totalHealth+=10*level;
      cout<<"You healed by resting Health is now "<<totalHealth<<endl;
      Sleep(1000);
      system("cls");
      HUD();
      }
      else if(choice==3){
        int temp=rand()%100+1;
        cout<<"You begin moving backwards...\n"<<endl;
        if(temp>=50){
          //Encounter a enemy
          createEnemy();
          string tempName=enemyNames[rand()%currentEnemyNum];
          cout<<"A "<<tempName<<"!    "<<"Prepare to fight!!"<<endl;
          currentEnemyName=tempName;
          Sleep(1000);
          combat();
        }
        cout<<"You find nothing of interest\n";
        Sleep(1000);
        system("cls");
        HUD();
        moving();
      }
  
      else{
        cout<<"Invalid Choice\n";
        Sleep(500);
        moving();
      }
    }

    void levelUp(){
      if(currentXP>=XptoLevel){
        XptoLevel+=floor(level+25*pow(2,level/7));
        totalHealth=floor(totalHealth+13*pow(2,level/8));
        if(level>=minLevel&&level<=maxLevel)
          level++;
        else
          level=60;
      maxHealth=totalHealth;
      cout<<"Your total health increased now!   Your Health is "<<totalHealth<<endl;
      cout<<"\n";
      Sleep(1000);
      levelUp();
      }     
      Sleep(2000);
      HUD();
    }
    
    void createEnemy(){
      enemyHP=30;
      enemyLevel=(rand()%3)+level;
     // if(enemyLevel==0)
      //  enemyLevel=(rand()%3)+level;
      enemyHP=(rand()%30)*enemyLevel;
      //if(enemyHP==0)
        //enemyHP=(rand()%30)*totalHealth;
      enemyXP=enemyHP;
      if(enemyHP==0)
        createEnemy();
      if(enemyLevel==0)
        createEnemy();
    }

};

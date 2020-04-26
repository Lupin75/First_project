#include<iostream>
using namespace std;

int input;
int counter=0;
int temp;
string tempName;
int choice;
string name;
int level=1;
int HP=0;
int health=100;
int totalHealth=0;
int maxHealth=0;
int enemyXP=0;
int enemyHP=0;
int enemyLevel=0;
string enemyNames[]={"Enemy1","Enemy2","Enemy3","Enemy4","Enemy5","Enemy6"};
int currentEnemyNum=5;
string currentEnemyName;
int playerAttack;
int playerDamage;
int enemyAttack;
int heal;
int currentXP=0;
int baseXP=83;
int XptoLevel=baseXP;
int minLevel=1;
int maxLevel=60;



//-------------------this function is to change a string to lower case----------------
string toSmall(string large){
    for(int i=0 ; i<large.size() ; i++){
        if(isalpha(large[i])!=0){
            switch(large[i]){
                case 'A':
                    large[i]='a';
                    break;
                case 'B':
                    large[i]='b';
                    break;
                case 'C':
                    large[i]='c';
                    break;
                case 'D':
                    large[i]='d';
                    break;
                case 'E':
                    large[i]='e';
                    break;
                case 'F':
                    large[i]='f';
                    break;
                case 'G':
                    large[i]='g';
                    break;
                case 'H':
                    large[i]='h';
                    break;
                case 'I':                        
                    large[i]='i';
                    break;
                case 'J':
                    large[i]='j';
                    break;
                case 'K':
                    large[i]='k';
                    break;
                case 'L':
                    large[i]='l';
                    break;
                case 'M':
                    large[i]='m';
                    break;
                case 'N':
                    large[i]='n';
                    break;
                case 'O':
                    large[i]='o';
                    break;
                case 'P':
                    large[i]='p';
                    break;
                case 'Q':
                    large[i]='q';
                    break;
                case 'R':
                    large[i]='r';
                    break;
                case 'S':
                    large[i]='s';
                    break;
                case 'T':
                    large[i]='t';
                    break;
                case 'U':
                    large[i]='u';
                    break;
                case 'V':
                    large[i]='v';
                    break;
                case 'W':                        
                    large[i]='w';
                    break;
                case 'X':
                    large[i]='x';
                    break;
                case 'Y':
                    large[i]='y';
                    break;
                case 'Z':
                    large[i]='z';
                    break;
                default:                        
                    large[i]=large[i];
                    break;
            }
        }
    }
    return large;    
}
//-----------------------------------------------------------------------------------------
//
//  main.cpp
//  과제1
//
//  Created by 최제현 on 2020/09/27.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int rollDice(void);

int main(int argc, const char * argv[]) {
    
    enum Status{CONTINUE, WON, LOST};
    int sum, myPoint;
    Status gameStatus;
    
    srand(time(0));
    sum = rollDice();
    switch(sum){
        case 7 :
        case 11: gameStatus = WON; break;
        case 2 :
        case 12: gameStatus = LOST; break;
        default : {
            gameStatus = CONTINUE;
            myPoint = sum;
            cout << "Point is " << myPoint << endl;
        }
    }
            while (gameStatus == CONTINUE){
                sum = rollDice();
                if (sum == myPoint)
                    gameStatus = WON;
                else if (sum == 7)
                    gameStatus = LOST;
            }
    
    if (gameStatus == WON)
        cout << "Player wins" <<endl;
    else
        cout << "Player loses" << endl;
    
    return 0;
}


int rollDice(void){
    
    int die1, die2;
    
    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    cout << die1 << " + " << die2 << " = " << die1 + die2 << endl;
    
    return die1 + die2;
}

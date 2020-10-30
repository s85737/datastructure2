//
//  main.cpp
//  date
//
//  Created by 최제현 on 2020/10/20.
//

#include "date_H.h"
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int month = 1, day = 1, year = 1900;
    int maxDays = 1;
    
    cout << "기준일 : ";
    cin >> month >> day >> year;
    cout << "간격(일) : ";
    cin >> maxDays;

    Date beforeBaseDate(month, day, year);
    Date afterBaseDate(month, day, year);
    
    for (int i = 1; i <= maxDays; ++i){
        beforeBaseDate.previousDay();
        afterBaseDate.nextDay();
    }
    
    cout << maxDays << "일 전 : ";
    beforeBaseDate.print();
    
    cout << maxDays << "일 후 : ";
    afterBaseDate.print();
    
    return 0;
}

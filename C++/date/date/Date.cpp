//
//  Date.cpp
//  date
//
//  Created by 최제현 on 2020/10/20.
//

#include "date_H.h"
#include <iostream>

using namespace std;



Date::Date(int m, int d, int y){setDate(m, d, y);}

void Date::setDate(int m, int d, int y) {setMonth(m); setDay(d); setYear(y);}

void Date::setMonth(int m) {month = (m <= 12 && m >= 1) ? m : 1;}

/**
 year 체크 1900년 미만이거나, 3000년을 초과할경우 1900으로 set
 @params y : year
 */
void Date::setYear(int y) {year = (y <= 3000 && y >= 1900) ? y : 1900; }

void Date::setDay(int d) {
    if(month == 2 && leapYear())
        day = (d <= 29 && d >= 1) ? d : 1;
    else
        day = (d <= monthDays() && d >= 1) ? d : 1;
}

int Date::getDay(){return day;}

int Date::getMonth(){return month;}

int Date::getYear(){return year;}

void Date::print(){cout << month << '-' << day << '-' << year << '\n';}

/**
    기준일에서 사용자가 입력한 일수 전의 값 set
 */

void Date::previousDay(){
    
    if((day - 1) != 0) setDay(day-1); //setDay는 0으로 바뀌지 않으므로
    else{
        if((month - 1) != 0) {
            setMonth(month - 1);
            day = monthDays(); // 해당 달 말일로 일수 조정
        }
        else{ // month 가 0이 되었을 떄
            month = 12;
            day = monthDays();
            setYear(year - 1);
        }
    }
    
}


/**
 기준일에서 사용자가 입력한 일수 후의 값 set
 */
void Date::nextDay(){
    setDay(day + 1);
    if (day == 1){
        setMonth(month + 1);
        if (month == 1) setYear(year + 1);
    }
}

/**
 윤년 체크: 4년으로 나누어 떨어지면 윤년 나누어 떨어지더라도 100으로 나누어 떨어지면 평년이다.
 @return 윤년일 경우 true 그외에는 false
 */
bool Date::leapYear(void) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

int Date::monthDays(void){
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 && leapYear() ? 29 : days[month - 1];
}

//
//  date_H.h
//  date
//
//  Created by 최제현 on 2020/10/20.
//

#ifndef date_H_h
#define date_H_h

class Date{
public: Date(int = 1, int =1, int = 1900);
    void print(void);
    void previousDay(void);
    void nextDay(void);
    void setDate(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth(void);
    int getDay(void);
    int getYear(void);
    bool leapYear(void);
    int monthDays(void);
private: int month;
    int day;
    int year;
};

#endif /* date_H_h */

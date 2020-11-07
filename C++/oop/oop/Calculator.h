//
//  Calculator.h
//  OOPproject2
//
//  Created by HeeJae Suh on 2020/10/26.
//

#ifndef Calculator_h
#define Calculator_h

#include "inf_int.h"
#include <iostream>
#include <cstring>
#include <string.h>

class Calculator{
private:
    inf_int num1, num2;
    inf_int result;
    inf_int add();
    inf_int sub();
    inf_int mult();
    void printResult(inf_int result);
public:
    Calculator();
    Calculator(char* str);
    Calculator(char* in_num1, char* oper, char* in_num2);
    ~Calculator();
};

#endif /* Calculator_hpp */

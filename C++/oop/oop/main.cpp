//
//  main.cpp
//  OOPproject2
//
//  Created by HeeJae Suh on 2020/10/25.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "inf_int.h"
#include <cstring>
#include "Calculator.h"
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
//    inf_int *num = new inf_int("4");
//    inf_int *num1 = new inf_int();
//    inf_int *num2 = new inf_int(20);
//    cout<<"inf_int num is: "<<num->getDigits()<<endl;
//    cout<<"inf_int num is: "<<num1->getDigits()<<endl;
//    cout<<"inf_int num is: "<<num2->getDigits()<<endl;
//    char* str =new char[5];
//    strcpy(str,"-12345");
//    cout<<strlen("-12345")<<endl;
//    cout<<strlen(str)<<endl;
//    cout<<"------------------------------------------------------------\n\n";

    
    cout<<"input : ";
    string str_buf[3];
    cin>>str_buf[0]>>str_buf[1]>>str_buf[2];
     
    char* input = new char[str_buf[0].length()+1];
    strcpy(input,str_buf[0].c_str());
    input[str_buf[0].length()] = 0;
    
    char* oper = new char[2];
    strcpy(oper,str_buf[1].c_str());
    oper[1] = 0;
    
    char* input2 = new char[str_buf[2].length()+1];
    strcpy(input2,str_buf[2].c_str());
    input2[str_buf[2].length()] = 0;
    
    Calculator* cal = new Calculator(input, oper, input2);
    
    
    Calculator* cal1 = new Calculator("123", "+", "456");
    return 0;
}

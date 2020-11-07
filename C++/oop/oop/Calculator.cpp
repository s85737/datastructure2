//
//  Calculator.cpp
//  OOPproject2
//
//  Created by HeeJae Suh on 2020/10/26.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include "inf_int.h"

#include <cstring>
#include <string>

inf_int Calculator::add(){
        this->result = this->num1 + this->num2;
        printResult(this->result);
        return this->result;
    };
inf_int Calculator::sub(){
        this->result = this->num1 - this->num2;
        printResult(this->result);
        return this->result;
    };
inf_int Calculator::mult(){
        this->result = this->num1 * this->num2;
        printResult(this->result);
        return this->result;
    };
void Calculator::printResult(inf_int result){
        int i=0;
        unsigned int len = result.getLength();
        char* digit = new char[len+1];
        char* result_digits = new char[len+1];
        result_digits = result.getDigits();
        digit[len] = 0;
        for(i=0;i<len;i++){
            std::cout<<result_digits[i];
        }
        std::cout<<"\n";

    };

    Calculator::Calculator(){
        
    };
    Calculator::~Calculator(){
        delete this;
    };
Calculator::Calculator(char* input){
        int i = 0;
    char *str[3] = {0};

    char *ptr = strtok(input, " ");
    while(ptr!=NULL){
        str[i] = ptr;
        i++;
        std::cout<<ptr;
        ptr = strtok(NULL," ");
    }

        this->num1 = inf_int(str[0]);
        this->num2 = inf_int(str[2]);

        switch(*(str[2])){
            case '+':
                add();

            case '-':
                sub();

            case '*':
                mult();

        }
};
Calculator::Calculator(char* in_num1, char* oper, char* in_num2){
        int i = 0;

        this->num1 = inf_int(in_num1);
        this->num2 = inf_int(in_num2);
    if(!strcmp(oper,"+")){
        add();
    }
    else if(!strcmp(oper,"-")){
        sub();
    }
    else if(!strcmp(oper,"*")){
        mult();
    }
};
    


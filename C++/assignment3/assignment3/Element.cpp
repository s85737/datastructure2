//
//  Element.cpp
//  assignment3
//
//  Created by 최제현 on 2020/11/01.
//

#include <iostream>
#include "Element_H.h"

using namespace std;

Element::Element(int element){
    setElement(element);
    this -> flag = false;
};

void Element::setElement(int element) {
    this -> element = element;
}

int Element::getElement(){
    return element;
}

bool Element::getFlag(){
    return flag;
}

void Element::setFlag(){
    this -> flag = true;
}

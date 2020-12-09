//
//  Sqaure.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Sqaure.hpp"

Square::Square(double length, double x, double y):Shape(x, y) {
    setLength(length);
    setArea();
    setClassName();
};


void Square::setLength(double length){
    if(!(length > 0)){
        cout << "length 가 1 이하입니다. default 값으로 수정합니다." << endl;
        length = 1;
    }
    this -> length = length;
}

double Square::getLength(){
    return length;
}

void Square::setArea(){
    this -> area = getLength() * getLength();
}

double Square::getArea(){
    return area;
}

void Square::setClassName(){
    this -> className = "Square";
}

string Square::getClassName(){
    return className;
}


void Square::printShape(){
    cout << getClassName() << " with side length " << getLength() <<"; ";
    this -> coord -> printCoordinate();
    cout << "area of "<< getArea() << endl <<endl;
}

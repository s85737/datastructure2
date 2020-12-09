//
//  Cube.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Cube.hpp"

Cube::Cube(double length, double x, double y):Shape(x, y) {
    setLength(length);
    setArea();
    setVolume();
    setClassName();
};


void Cube::setLength(double length){
    if(!(length > 0)){
        cout << "Length 가 1 이하입니다. default 값으로 수정합니다." << endl;
        length = 1;
    }
    this -> length = length;
}

double Cube::getLength(){
    return length;
}

void Cube::setArea(){
    this -> area = 6 * getLength() * getLength();
}

double Cube::getArea(){
    return area;
}

void Cube::setClassName(){
    this -> className = "Cube";
}

string Cube::getClassName(){
    return className;
}

void Cube::setVolume(){
    this -> volume = getLength() * getLength() * getLength();
}

double Cube::getVolume(){
    return volume;
}

void Cube::printShape(){
    cout << getClassName() << " with side Length " << getLength() <<"; ";
    this -> coord -> printCoordinate();
    cout << "area of "<< getArea() <<"; " << " volume of " << getVolume() << endl <<endl;
}

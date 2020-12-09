//
//  Coordinate.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Coordinate.hpp"
#include <iostream>
using namespace std;

Coordinate:: Coordinate(double x, double y){
    setCoordinate(x, y);
}

void Coordinate::setCoordinate(double x, double y){
    
    this -> x = x;
    this -> y = y;
}

double Coordinate::getX(){
    
    return x;
    
}

double Coordinate::getY(){
    
    return y;
}

//outStream을 계속해서 받을 수 있도록 스트림 return 
ostream &operator<<(ostream &o, Coordinate &coord){
    o<< "(" << coord.getX() << ", " << coord.getY() << ");"<<endl;
    return o;
}

void Coordinate::printCoordinate(){
    Coordinate coord(getX(), getY());
    cout << "center at " << coord << endl;
}

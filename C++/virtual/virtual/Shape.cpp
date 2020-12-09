//
//  Shape.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Shape.hpp"
#include "Coordinate.hpp"
#include <string>

using namespace std;

Shape::Shape(double x, double y){
    setShape(x, y);
    setClassName();
}

void Shape::setShape(double x, double y){
    
    this -> x = x;
    this -> y = y;
    Coordinate* coord = new Coordinate(x, y);
    this -> coord = coord;
    
}

double Shape::getX(){
    return this -> x;
}

double Shape::getY(){
    return this -> y;
}

void Shape::printCoord(){
    
    this -> coord -> printCoordinate();
    
}

void Shape::setClassName(){
    this -> className = "Shape";
}

string Shape::getClassName(){
    return className;
}


void Shape::printShape(){
    cout << getClassName();
    this -> coord -> printCoordinate();
}

ostream &operator<<(ostream& ostream, Shape &s){
    s.printShape();
    return ostream;
}

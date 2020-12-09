//
//  Circle.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Circle.hpp"


Circle::Circle(double radious, double x, double y):Shape(x, y) {
    setRadius(radious);
    setArea();
    setClassName();
};

void Circle::setRadius(double radious){
    if(!(radious > 0)){
        cout << "radious 가 1 이하입니다. default 값으로 수정합니다." << endl;
        radious = 1;
    }
    this -> radius = radious;
    
}

double Circle::getRadius(){
    return radius;
}
void Circle::setArea(){
    this -> area = getRadius() * getRadius() * 3.141592;
}

double Circle::getArea(){
    return area;
}

void Circle::setClassName(){
    this -> className = "Circle";
}

string Circle::getClassName(){
    return className;
}


void Circle::printShape(){
    cout << getClassName() << " with radius " << getRadius() <<"; ";
    this -> coord -> printCoordinate();
    cout << "area of "<< getArea() << endl <<endl;
}

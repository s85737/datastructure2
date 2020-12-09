//
//  Sphere.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include "Sphere.hpp"

Sphere::Sphere(double radius, double x, double y):Shape(x, y) {
    setRadius(radius);
    setArea();
    setVolume();
    setClassName();
};


void Sphere::setRadius(double radius){
    if(!(radius > 0)){
        cout << "radius 가 1 이하입니다. default 값으로 수정합니다." << endl;
        radius = 1;
    }
    this -> radius = radius;
}

double Sphere::getRadius(){
    return radius;
}

void Sphere::setArea(){
    this -> area = 4 * getRadius() * getRadius() * 3.141592;
}

double Sphere::getArea(){
    return area;
}

void Sphere::setClassName(){
    this -> className = "Sphere";
}

string Sphere::getClassName(){
    return className;
}

void Sphere::setVolume(){
    this -> volume = getRadius() * getRadius() * getRadius() * 3.141592 * 4 / 3;
}

double Sphere::getVolume(){
    return volume;
}

void Sphere::printShape(){
    cout << getClassName() << " with side radius " << getRadius() <<"; ";
    this -> coord -> printCoordinate();
    cout << "area of "<< getArea() <<"; " << " volume of " << getVolume() << endl <<endl;
}

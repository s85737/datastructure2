//
//  main.cpp
//  실습
//
//  Created by 최제현 on 2020/10/04.
//

#include <iostream>
#include "circle.h"

using namespace std;

void Circle::setRadius(int r) {radius = r;}
double Circle::getArea() {return 3.14*radius*radius;}

int main(int argc, const char * argv[]) {
    
    
    Circle circle1; circle1.setRadius(1); cout<<circle1.getArea()<<endl;
    Circle circle2; circle2.setRadius(2); cout<<circle2.getArea()<<endl;
    
    return 0;
}

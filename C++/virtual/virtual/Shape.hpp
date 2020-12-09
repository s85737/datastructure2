//
//  Shape.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>
#include "Coordinate.hpp"

using namespace std;

// shape 가 공통적으로 가저야 할 값들 구현
class Shape{
    
public:
    Shape(double x=0, double y=0);
    double getX();
    double getY();
    virtual void printShape();
    virtual void setArea() =0;
    virtual string getClassName();
    virtual void setClassName();
    void setShape(double, double);
    void printCoord();
    friend ostream &operator<<(ostream&, Shape&);
protected:
    string className;
    double x;
    double y;
    Coordinate* coord;
    
};

#endif /* Shape_hpp */

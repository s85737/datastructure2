//
//  Sqaure.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Sqaure_hpp
#define Sqaure_hpp

#include <iostream>
#include "Shape.hpp"

class Square : public Shape {
public:
    Square(double length = 1, double x = 0, double y =0);
    virtual void printShape();
    virtual string getClassName();
    virtual void setClassName();
    double getLength();
    void setLength(double);
    double getArea();
    void setArea();
    friend ostream &operator<<(ostream, const Shape&);
protected:
    string className;
    double length;
    double area;
};

#endif /* Sqaure_hpp */

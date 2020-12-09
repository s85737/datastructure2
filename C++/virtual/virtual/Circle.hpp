//
//  Circle.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include "Shape.hpp"

class Circle : public Shape {
public:
    Circle(double radious = 1, double x = 0, double y =0);
    virtual double getRadius();
    virtual void printShape();
    virtual string getClassName();
    virtual void setClassName();
    double getArea();
    void setRadius(double);
    void setArea();
    friend ostream &operator<<(ostream, Circle&);
protected:
    string className;
    double radius;
    double area;
};

#endif /* Circle_hpp */

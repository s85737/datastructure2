//
//  Sphere.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <iostream>
#include "Shape.hpp"

class Sphere : public Shape {
public:
    Sphere(double radious = 1, double x = 0, double y =0);
    virtual void printShape();
    virtual string getClassName();
    virtual void setClassName();
    double getRadius();
    void setRadius(double);
    double getArea();
    void setArea();
    double getVolume();
    void setVolume();
    friend ostream &operator<<(ostream, const Shape&);
protected:
    string className;
    double radius;
    double area;
    double volume;
};

#endif /* Sphere_hpp */

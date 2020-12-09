//
//  Cube.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <iostream>
#include "Shape.hpp"

class Cube : public Shape {
public:
    Cube(double length = 1, double x = 0, double y = 0);
    virtual void printShape();
    virtual string getClassName();
    virtual void setClassName();
    double getLength();
    void setLength(double);
    double getArea();
    void setArea();
    double getVolume();
    void setVolume();
    friend ostream &operator<<(ostream, const Shape&);
protected:
    string className;
    double length;
    double area;
    double volume;
};


#endif /* Cube_hpp */

//
//  Coordinate.hpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <iostream>
using namespace std;

// 좌표 객체
class Coordinate{
public:
    Coordinate(double, double);
    void setCoordinate(double, double);
    void printCoordinate();
    double getX();
    double getY();
    //좌표값을 원하는 탬플릿으로 출력하기 위한 연산자 중복
    friend ostream &operator<<(ostream&, Coordinate&);
private:
    double x, y;
};

#endif /* Coordinate_hpp */

//
//  main.cpp
//  virtual
//
//  Created by 최제현 on 2020/12/05.
//

#include <iostream>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Sqaure.hpp"
#include "Sphere.hpp"
#include "Cube.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
//    Circle cir( 3.5, 6, 9 );
//
//    Square sqr( 12, 2, 2 );
//
//    Sphere sph( 5, 1.5, 4.5 );
//
//    Cube cub( 2.2 );
//
//    Shape *ptr[ 4 ] = { &cir, &sqr, &sph, &cub };
//
//    for ( int x = 0; x < 4; ++x )
//    cout << *( ptr[ x ] ) << '\n';


    
    Shape *p[3];
    p[0] = new Oval("oval1", 10, 20);
    p[0] = new Rectangular("rect1", 30, 40);
    p[0] = new Triangular("tri1", 30, 40);
    


    return 0;
}

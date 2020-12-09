//
//  main.cpp
//  myMatrix
//
//  Created by 최제현 on 2020/11/15.
//

#include <iostream>
#include "CArray.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

//    MyMatrix m1(3,3), m2(3,3), m3, m4, m5, m6, m7;
//
//    cin >> m1;
//
//    cin >> m2;
//
//
//    m3 = -m1;       cout << m3 << endl;
//    m4 = m1 + m2;   cout << m4 << endl;
//    m5 = m1 - m2;   cout << m5 << endl;
//    m6 = m1 * m2;   cout << m6 << endl;
//    m7 = 2 * m1;    cout << m7 << endl;
    
    CArray a1;
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;

    cout<<a1<<endl;
    
    CArray a2;
    a2[0] = 1.1;
    a2[1] = 2.2;
    
    cout << a2 << endl;
    
    return 0;
}

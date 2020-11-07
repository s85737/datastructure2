//
//  main.cpp
//  assignment3
//
//  Created by 최제현 on 2020/11/01.
//

#include <iostream>
#include <vector>
#include "IntegerSet_H.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    IntegerSet setA, setB, setC, setD, setE;
    
    cout << "집합 A: \n"; setA.inputSet();
    cout << "집합 B: \n"; setB.inputSet();
    
    cout <<"A = "; setA.setPrint();
    cout <<"B = "; setB.setPrint();
    
    setC = intUnion(setA, setB);
    cout << "집합 C: \n"; setC.setPrint();
    
    setD = intersection(setA, setB);
    cout << "집합 D: \n"; setD.setPrint();
    
    setE = difference(setA, setB);
    cout << "집합 E: \n"; setE.setPrint();

    
    return 0;
}

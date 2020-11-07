//
//  IntegerSet.h
//  assignment3
//
//  Created by 최제현 on 2020/11/01.
//

#ifndef IntegerSet_H_h
#define IntegerSet_H_h
#include "Element_H.h"

using namespace std;

class IntegerSet {
    
    private : Element* elementArray = new Element[100]; //임의로 최대 100개 저장
    int index;
    public : void inputSet();
    void setArray(int, int);
    void setPrint();
    friend IntegerSet intUnion(IntegerSet, IntegerSet);
    friend IntegerSet intersection(IntegerSet, IntegerSet);
    friend IntegerSet difference(IntegerSet, IntegerSet);
    
};


#endif /* IntegerSet_h */

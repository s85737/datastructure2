//
//  CArray.hpp
//  myMatrix
//
//  Created by 최제현 on 2020/12/09.
//

#ifndef CArray_h
#define CArray_h

#include <iostream>
using namespace std;

class CArray{
private:
    float* array;
    float size;
public:
    CArray();
    friend ostream& operator<<(ostream& output, CArray& right);
    float &operator[](int index);
    void init();
};

#endif /* CArray_h */

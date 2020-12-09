//
//  CArray.cpp
//  myMatrix
//
//  Created by 최제현 on 2020/12/09.
//

#include "CArray.hpp"
#include <iostream>

using namespace std;

CArray::CArray()
{
    size = 5;
    array = new float[size];
    init();
}

ostream& operator<<(ostream& output, CArray& right){
    for (int i =0; i < right.size; i++)
    {
        if(!(right.array[i] == 0))
        output << right.array[i] << " ";
    }
    return output;
}

float &CArray::operator[](int index)
{
    return array[index];
}

void CArray::init()
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}


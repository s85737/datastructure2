//
//  MyMatrix.h
//  myMatrix
//
//  Created by 최제현 on 2020/11/15.
//

#ifndef MyMatrix_h
#define MyMatrix_h

#include <iostream>
using namespace std;

class MyMatrix{
    
private:
    int column = 0;
    int row = 0;
    int** matrix;
public:
    MyMatrix(int column, int row);
    MyMatrix();
    int** makeMatrix();
    bool mulCheck(const MyMatrix& right) const;
    bool subCheck(const MyMatrix& right) const;
    const MyMatrix operator=(const MyMatrix& right);
    const MyMatrix operator+(const MyMatrix& right);
    const MyMatrix operator-();
    const MyMatrix operator-(const MyMatrix& right);
    const MyMatrix operator*(const MyMatrix& right);
    friend MyMatrix operator*(const int num, const MyMatrix& right);
    friend MyMatrix operator*(const int num, const MyMatrix& right);
    friend istream& operator>>(istream& is, MyMatrix& right);
    friend ostream& operator<<(ostream& output, MyMatrix& right);
    void printMatrix();
    
};
#endif /* MyMatrix_h */

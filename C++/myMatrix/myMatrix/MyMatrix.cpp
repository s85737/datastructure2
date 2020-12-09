//
//  MyMatrix.cpp
//  myMatrix
//
//  Created by 최제현 on 2020/11/15.
//

#include <iostream>
#include "MyMatrix.h"


using namespace std;

MyMatrix::MyMatrix(int column, int row){
    
    this -> column = column;
    this -> row = row;
    this -> matrix = makeMatrix();
    
}

MyMatrix::MyMatrix(){
    
    this -> column = 0;
    this -> row = 0;
    this -> matrix = makeMatrix();
    
}

/**
 2차원 배열 할당
 @return 2차원 배열의 주소값
 */
int** MyMatrix::makeMatrix(){
    
    int **matrix = new int*[this -> column];
    
    for(int columnIndex = 0; columnIndex < this -> column; columnIndex++)
        matrix[columnIndex] = new int[this -> row];
    
    for(int columnIndex = 0; columnIndex < this -> column; columnIndex++)
    {
        for(int rowIndex = 0; rowIndex < this -> row; rowIndex++)
        {
            matrix[columnIndex][rowIndex] = 0; // 순서대로 값 입력
        }
    }
    
    return matrix;
}

/**
 계산을 원하는 행렬이 더하기 연산을 할 수 있는지 체크하는 메서드
 덧셈 뺄셈은 행렬의 크기가 같아야 연산가능
 @return 더하기 연산을 할 수 있으면 true 리턴
 */

bool MyMatrix::subCheck(const MyMatrix& right) const {
    if(this -> column == right.column && this -> row == right.row)
        return true;
    else
        return false;
}

/**
 계산을 원하는 행렬이 곱하기 연산을 할 수 있는지 체크하는 메서드
 왼쪽의 열과 오른쪽의 행이 같아야 연산 가능
 @params right hand side
 @return 더하기 연산을 할 수 있으면 true 리턴
 */

bool MyMatrix::mulCheck(const MyMatrix &right) const {
    if(this -> row == right.column)
        return true;
    else
        return false;
}

/**
 테스트용
 행열 출력 메서드
 */

void MyMatrix::printMatrix(){

    
    for(int columnIndex = 0; columnIndex < this -> column; columnIndex++)
    {
        cout << "|";
        for(int rowIndex = 0; rowIndex < this -> row; rowIndex++)
        {
            cout << " " << this -> matrix[columnIndex][rowIndex] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

ostream& operator<<(ostream& output, MyMatrix& right){
    
    
    for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
    {
        output << "|";
        for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
        {
            output << " " << right.matrix[columnIndex][rowIndex] << " ";
        }
        output << "|";
        output << endl;
    }
    
    return output;
}

/*
 
 */

istream& operator>>(istream& is, MyMatrix& right){

    cout << "입력 - " << endl;
    for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
    {
        for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
        {
            cout << columnIndex << "행 " << rowIndex << "열 : ";
            is >> right.matrix[columnIndex][rowIndex]; // 순서대로 값 입력
        }
    }
    
    return is;
}


/**
 연산자 중복 = operator
 새로운 MyMatrix 객체를 생성하여, RHS 객체의 값 모두 복사
 @params right right hand side
 @return 더하고 난 뒤 결과 행렬
 */


const MyMatrix MyMatrix::operator=(const MyMatrix& right){
    
    
    if(&right != this){
        this -> column = right.column;
        this -> row = right.row;
        this -> matrix = makeMatrix();
        
        for(int columnIndex = 0; columnIndex < this -> column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < this -> row; rowIndex++){
                this->matrix[columnIndex][rowIndex] = right.matrix[columnIndex][rowIndex];
            }
        }
    }

    
    return *this;
}
/**
 연산자 중복 + operator
 새로운 MyMatrix 객체를 생성하여, 더하기 연산 후 저장
 @params right right hand side
 @return 더하고 난 뒤 결과 행렬
 */
const MyMatrix MyMatrix::operator+(const MyMatrix& right){
    
    //현재 matrix를 resultMatrix에 깊은 복사
    MyMatrix* resultMatrix = new MyMatrix(this -> column, this -> row);
    resultMatrix -> matrix = resultMatrix -> makeMatrix();
    
    if(subCheck(right))
    {

        for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
            {
                resultMatrix -> matrix[columnIndex][rowIndex] = this -> matrix[columnIndex][rowIndex] + right.matrix[columnIndex][rowIndex];
            }
        }
        
        return* resultMatrix;
    }
    else
    {
        cout << "더하기 연산을 진행할 수 없습니다. 행렬을 다시 입력해주세요." << endl;
        exit(-1);
    }
}

/**
 연산자 중복 - operator
 새로운 MyMatrix 객체를 생성하여, 빼기 연산 후 복사
 @params right right hand side
 @return 빼고 난 뒤 결과 행렬
 */

const MyMatrix MyMatrix::operator-(const MyMatrix& right){

    MyMatrix* resultMatrix = new MyMatrix(this -> column, this -> row);
    resultMatrix -> matrix = resultMatrix -> makeMatrix();
    
    if(subCheck(right))
    {
        
        for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
            {
                resultMatrix -> matrix[columnIndex][rowIndex] = this -> matrix[columnIndex][rowIndex] - right.matrix[columnIndex][rowIndex];
            }
        }
        
        return* resultMatrix;
    }
    else
    {
        cout << "빼기 연산을 진행할 수 없습니다. 행렬을 다시 입력해주세요." << endl;
        exit(-1);
    }
    
}

/**
 연산자 중복 - operator
 새로운 MyMatrix 객체를 생성하여, 해당 메트릭스를 음수값으로 변환
 @return  결과 행렬
 */

const MyMatrix MyMatrix::operator-(){

    MyMatrix* resultMatrix = new MyMatrix(this -> column, this -> row);
    resultMatrix -> matrix = resultMatrix -> makeMatrix();
        
        for(int columnIndex = 0; columnIndex < this -> column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < this -> row; rowIndex++)
            {
                resultMatrix -> matrix[columnIndex][rowIndex] = -(this -> matrix[columnIndex][rowIndex]);
            }
        }
        
        return* resultMatrix;

    
}

/**
 연산자 중복 정수*matrix operator
 새로운 MyMatrix 객체를 생성하여, 해당 메트릭스를 정수배
 @return  결과 행렬
 */

MyMatrix operator*(const int num, const MyMatrix& right){

    MyMatrix* resultMatrix = new MyMatrix(right.column, right.row);
    resultMatrix -> matrix = resultMatrix -> makeMatrix();

    
        for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
            {
                resultMatrix -> matrix[columnIndex][rowIndex] = num * (right.matrix[columnIndex][rowIndex]);
            }
        }
        
        return* resultMatrix;
    

}

/**
 연산자 중복 * operator
 새로운 MyMatrix 객체를 생성하여, 두 행렬을 곱함
 @return  결과 행렬
 */

const MyMatrix MyMatrix:: operator*(const MyMatrix &right){
    
    MyMatrix* resultMatrix = new MyMatrix(this -> column, this -> row);
    resultMatrix -> matrix = resultMatrix -> makeMatrix();

    if(mulCheck(right))
    {
        for(int columnIndex = 0; columnIndex < right.column; columnIndex++)
        {
            for(int rowIndex = 0; rowIndex < right.row; rowIndex++)
            {
                int mulIndex = 0;
                while(mulIndex < right.column){
                    resultMatrix -> matrix[columnIndex][rowIndex] += this -> matrix[columnIndex][mulIndex] * right.matrix[mulIndex][rowIndex];
                    mulIndex++;
                }
            }
        }
        
    }
    else
    {
        cout << "곱하기 연산을 진행할 수 없습니다. 행렬을 다시 입력해주세요." << endl;
        exit(-1);
    }

    return* resultMatrix;
}




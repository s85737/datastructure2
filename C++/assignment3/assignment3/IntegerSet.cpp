//
//  IntegerSet.cpp
//  assignment3
//
//  Created by 최제현 on 2020/11/01.
//

#include <iostream>
#include "IntegerSet_H.h"

void IntegerSet::inputSet(){
    
    int num;
    
    for(int index =0; index <= 100; index++){
        
        cout<<"\n"<<index+1<<"번째 원소(-1 : 종료):";
        cin>>num;
        
        if(num <= -1)
        {
            this -> index = index; // 최종 저장된 인덱스 저장
            break;
        }
        
        setArray(num, index);
        
    }
    
}

void IntegerSet::setArray(int num, int index){
    
    this -> elementArray[index].setElement(num);
    
}

void IntegerSet::setPrint(){
    
    cout<<"{";
    for(int i = 0; i < this -> index; i++)
    {
        cout<<" "<<elementArray[i].getElement();
    }
    cout<<" }\n";
    
}

/**
 파라미터로 넘어온 set A 와 setB의 합집합을 구하는 함수
 @params  setA : 아규먼트로 넘겨준 setA와 setB
 @return setA :  합집합의 결과값
 */

IntegerSet intUnion(IntegerSet setA, IntegerSet setB){
    
    //계산의 편의성을 위해 setA와 setB의 교집합을 구한다.
    IntegerSet setBuffer = intersection(setA, setB);
    
    int totalIndex = setA.index+setB.index-setBuffer.index;
    int bIndex=0;
    
    //중복되는 숫자를 B에서 지워버리고 더해주기 위해 setB의 중복값의 플레그를 true로 바꾸어 준다.
    for (int bufIndex = 0; bufIndex < setBuffer.index; bufIndex++)
    {
        for(int bIndex = 0; bIndex < setB.index; bIndex++)
        {
            if(setBuffer.elementArray[bufIndex].getElement() == setB.elementArray[bIndex].getElement())
                setB.elementArray[bIndex].setFlag();
        }
    }

    
    //setB의 element의 flag가 true이면 그 순서는 넘어간다
    for(int aIndex = setA.index; aIndex < totalIndex; aIndex++)
    {
        if(setB.elementArray[bIndex].getFlag() == true)
        {
            aIndex--; //flag가 true면 A의 인덱스인 aIndex는 그대로 두고, b의 index는 증가
            bIndex++;
        }
        else
        {
            setA.elementArray[aIndex].setElement(setB.elementArray[bIndex].getElement());
            bIndex++;
        }
    }
    
    setA.index = totalIndex;
    
    return setA;
}

/**
 파라미터로 넘어온 set A 와 setB의 교집합을 구하는 함수
 @params  setA : 아규먼트로 넘겨준 setA와 setB
 @return setBuffer :  교집합의 결과값
 */

IntegerSet intersection(IntegerSet setA, IntegerSet setB){
    
    IntegerSet setBuffer;
    int bufferIndex = 0;
    
    
    // setA의 element와 setB의 element를 전체 탐색 후 같은값이 있으면, setBuffer에 저장
    for(int aIndex = 0; aIndex<setA.index; aIndex++)
    {
        for(int bIndex = 0; bIndex< setB.index; bIndex++)
        {
            if(setA.elementArray[aIndex].getElement() == setB.elementArray[bIndex].getElement())
            {
                setBuffer.elementArray[bufferIndex].setElement(setA.elementArray[aIndex].getElement());
                bufferIndex++;
            }
        }
    }
    
    setBuffer.index = bufferIndex;
    
    
    return setBuffer;
}


/**
 파라미터로 넘어온 set A 와 setB의 차집합을 구하는 함수
 @params  setA : 아규먼트로 넘겨준 setA와 setB
 @return setBuffer :  차집합의 결과값
 */

IntegerSet difference(IntegerSet setA, IntegerSet setB){
    
    //계산의 편의를 위해 setA와 setB의 교집합을 구한다.
    IntegerSet setBuffer = intersection(setA, setB);
    IntegerSet setResult;
    int totalIndex = setA.index-setBuffer.index;
    int rIndex=0;
    
    //중복되는 숫자를 A에서 지워버리고 다시 적기위해 setA의 중복값의 플레그를 true로 바꾸어 준다.
    for (int bufIndex = 0; bufIndex < setBuffer.index; bufIndex++)
    {
        for(int aIndex = 0; aIndex < setA.index; aIndex++)
        {
            if(setBuffer.elementArray[bufIndex].getElement() == setA.elementArray[aIndex].getElement())
                setA.elementArray[aIndex].setFlag();
        }
    }
    
    //setA의 element의 flag가 true이면 그 순서는 넘어간다.
    for(int aIndex = 0; aIndex < setA.index; aIndex++)
    {
        if(setA.elementArray[aIndex].getFlag() == false)
        {
            setResult.elementArray[rIndex].setElement(setA.elementArray[aIndex].getElement());
            rIndex++;
        }
       
    }
    
    setResult.index = totalIndex;
    
    return setResult;
}

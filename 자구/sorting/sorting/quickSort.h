//
//  quickSort.h
//  sorting
//
//  Created by 최제현 on 2020/12/06.
//

#ifndef quickSort_h
#define quickSort_h

#include "BSsort.h"

void swap(int list[], int left, int right){
    int temp;
    temp = list[left];
    list[left] = list [right];
    list [right] = temp;
}
/**
 list의 왼쪽숫자, 중간숫자, 가장 오른쪽 숫자중 중간값으로 피봇을 정하는 함수
 @params list : 리스트 low : 리스트의 제일 왼쪽 index  high : 리스트의 제일 오른쪽 index
 @return 피봇으로 정할 중간값
 */

int getPivot(int list[], int low, int high){
    int mid = (low + high) / 2;
    int numMid=0;
    int numList[3];
    
    numList[0] = list[low];
    numList[1] = list[mid];
    numList[2] = list[high];
    
    insertionSortASC(numList, 3);
    
    numMid = numList[1];
    
    return numMid;
}

int partition(int list[], int low, int high){
    int left, right;
    int pivot_item = getPivot(list, low, high);
//    int left, right, pivot_item = list[low];
    
    left = low;
    right = high;
    
    while (left < right)
    {
        // item < pivot 인 동안 왼쪽으로 옮김
        while (list[left] <= pivot_item)
            left++;
        
        // item > pivot 인 동안 오른쪽으로 옮김
        
        while(list[right] > pivot_item)
            right--;
        
        if(left < right)
            swap(list, left, right);
    }
    
    //right 가 마지막 pivot의 위치이다.
    list[low] = list[right];
    list[right] = pivot_item;
    return right;
    
}



void quickSort(int list[], int low, int high){
    int pivot;
    if (high > low)
    {
        
        pivot = partition(list, low, high);
        quickSort(list, low, pivot-1);
        quickSort(list, pivot + 1, high);

    }
}



#endif /* quickSort_h */

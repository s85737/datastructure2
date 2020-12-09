//
//  mergeSort.h
//  sorting
//
//  Created by 최제현 on 2020/12/06.
//

#ifndef mergeSort_h
#define mergeSort_h



void mergeASC(int list[], int temp[], int left, int mid, int right){
    
    int i, j, k, l;
    i = left; j = mid + 1; k = left;
    
    /* 분할 정렬된 list의 합병 */
    
    while (i <= mid && j <= right){
        if (list[i] <= list[j])
            temp[k++] = list[i++]; //left가 작으면 left copy
        else
            temp[k++] = list[j++]; //right가 작으면 right copy
    }
     
    if(i > mid) //남아 있는 레코드의 일괄 복사
    {
        for (l = j; l <= right; l++)
        {
            temp[k++] = list[l];
        }
        
    }
    else //남아 있는 레코드의 일괄 복사
    {
        for (l = i; l <= mid; l++)
        {
            temp[k++] = list[l];
        }
        
    }
    
    // 배열 sorted[]의 리스트를 배열 list[]로 재복사
    for(l = left; l <= right; l++)
    {
        list[l] = temp[l];
    }
    
}

void mergeSortASC(int list[], int temp[], int left, int right){
    
    int mid;
    
    if(left < right) {
        mid = (left + right) / 2; //리스트의 균등 분할
        mergeSortASC(list, temp, left, mid); //부분 리스트 정렬
        mergeSortASC(list, temp, mid + 1, right);
        mergeASC(list, temp, left, mid, right); //합병
    }
}


#endif /* mergeSort_h */

//
//  main.c
//  sorting
//
//  Created by 최제현 on 2020/12/06.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "mergeSort.h"
#include "BSsort.h"
#include "quickSort.h"
//#include "heapArray.h"
//#include "BST.h"
#define MAX_SIZE 15


int main(int argc, const char * argv[]) {
    
    int i, n = MAX_SIZE;
    int list[MAX_SIZE];
    int temp[MAX_SIZE];
    
    srand(time(NULL));
    
    for ( i = 0; i <n; i++)
        list[i] = rand () % 100 + 1;
    
    printf("Before sorting \t :");
    for (i = 0; i < n; i++)
    printf("%d ", list[i]);
    
//    bubbleSortASC(list ,n);
//    selectionSortASC(list , n);
//    insertionSortASC(list, n);
//    mergeSortASC(list, temp, 0, n-1);
    quickSort(list, 0, n-1);
    
    printf("\n After Sorting\t :");
    for (i = 0; i < n; i++)
    {
    printf("%d ", list[i]);
    }
    printf("\n");
    
    
    return 0;
}

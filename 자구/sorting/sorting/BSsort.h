//
//  BSsort.h
//  sorting
//
//  Created by 최제현 on 2020/12/06.
//

#ifndef BSsort_h
#define BSsort_h

void bubbleSortASC(int A[], int n){
    for (int pass = n - 1; pass >= 0; pass--)
    {
        for (int i = 0; i < pass; i++)
        {
            if(A[i] > A[i + 1])
            {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

//void bubbleSortSwap(int A[], int n){
//
//    for (int pass = n - 1; pass >= 0 && swapped ; pass--)
//    {
//        for (int i = 0; i < pass; i++)
//        {
//            if(A[i] > A[i + 1])
//            {
//                int temp = A[i];
//                A[i] = A[i + 1];
//                A[i + 1] = temp;
//            }
//        }
//    }
//}


void bubbleSortDES(int A[], int n){
    for (int pass = n - 1; pass >= 0; pass--)
    {
        for (int i = 0; i < pass; i++)
        {
            if(A[i] < A[i + 1])
            {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

void selectionSortASC(int A[], int n){
    int i, j, min, temp;
    for (i = 0; i < n -1; i++)
    {
        min = i;
        for (j = i +1; j <n ; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    
}

void selectionSortDES(int A[], int n){
    int i, j, max, temp;
    for (i = 0; i < n -1; i++)
    {
        max = i;
        for (j = i +1; j <n ; j++)
        {
            if (A[j] > A[max])
                max = j;
        }
        
        temp = A[max];
        A[max] = A[i];
        A[i] = temp;
    }
    
}

void insertionSortASC(int A[], int n){
    int i, j, v;
    for (i = 1; i <= n - 1; i++)
    {
        v = A[i];
        j = i;
    
    
        while(A[j -1] > v && j >= 1)
        {
            A[j] = A[j-1];
            j--;
        }
    
    A[j] = v;
    }
}

void insertionSortDES(int A[], int n){
    int i, j, v;
    for (i = 1; i <= n - 1; i++)
    {
        v = A[i];
        j = i;
    
    
        while(A[j -1] < v && j >= 1)
        {
            A[j] = A[j-1];
            j--;
        }
    
    A[j] = v;
    }
}


#endif /* BSsort_h */

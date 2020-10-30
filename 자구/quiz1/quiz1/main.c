//
//  main.c
//  quiz1
//
//  Created by 최제현 on 2020/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeNode.h"
#define RandBig() (rand()*rand())

//100만개 150만개 200만게 계쏙해서 증가



int sequentialSearch(int list[], int n, int ranKey){
    int i;
    for (i = 0; i < n; i++) if(list[i] == ranKey) return i;
    return -1;
}

double seqSrchAvgTime(int* list, int n, int iter){
    int i;
    clock_t t0, t1;
    t0 = clock();
    for(i = 0; i < iter; i++) sequentialSearch(list, n, RandBig());
    t1 = clock();
    return (double)(t1-t0) / (CLOCKS_PER_SEC * iter);
}

double BSTSrchAvgTime(TreeNode* root, int n, int iter){
    int i;
    clock_t t0, t1;
    t0 = clock();
    for(i = 0; i < iter; i++) root = treeSearch(root, RandBig());
    t1 = clock();
    return (double)(t1-t0) / (CLOCKS_PER_SEC * iter);
}



int main(int argc, const char * argv[]) {
    
    unsigned int whatTime;
    unsigned int value;
    double duration;
    clock_t t0, t1;
    printf("난수발생 횟수 입력 : ");
    scanf("%d", &whatTime);
    srand((unsigned int)time(NULL));
    
    int* arr;
    
    arr = (int *)malloc(sizeof(int) * whatTime);
    
    printf("sequential Search\n");
    for(int i = 1; i < 21; i++){
        arr = (int *)realloc(arr, sizeof(int) * whatTime * i);
        printf("%d회 생성", (whatTime * i));
        for(int j = 0; j < (whatTime * i); j++){
            value = rand() % 100;
            arr[j] = value;
        }
        duration = seqSrchAvgTime(arr, whatTime, 50);
        printf("\t%lf초 \n\n", duration);
        
            }
    
    printf("BSTree Insert and Search\n ");
    
    TreeNode* root = NULL;
    
    for(int i = 1; i < 21; i++){
        printf("%d회 생성", (whatTime * i));
        
        t0 = clock();
        for(int j = 0; j < whatTime * i; j++) root = insertNode(root, RandBig());
        t1 = clock();
        duration = (double)(t1-t0) / (CLOCKS_PER_SEC * 500000);
        printf("\t\t%d회 insert", (whatTime * i));
        printf("\t%lf초", duration);
        
        
        duration = BSTSrchAvgTime(root, whatTime, 500000);
        printf("\t\tsearch", (whatTime * i));
        printf("\t%lf초 \n\n", duration);
        free(root);
        root = NULL;
        
    }
    
    
    
    
    return 0;
}

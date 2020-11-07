
//
//  main.c
//  quiz1
//
//  Created by 최제현 on 2020/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RandBig() (rand()*rand())

//100만개 150만개 200만게 계속해서 증가

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
        arr = (int *)realloc(arr, sizeof(int) * whatTime * i); //배열이 가득 차는것을 대비하여 다시 매모리를 할당
        printf("%d회 생성", (whatTime * i));
        for(int j = 0; j < (whatTime * i); j++){  // 배열에서 처음부터 끝까지 다시 값을 삽입
            value = rand() % 100;
            arr[j] = value;
        }
        duration = seqSrchAvgTime(arr, whatTime, 50);
        printf("\t%lf초 \n\n", duration);
        
            }
    
    return 0;
}


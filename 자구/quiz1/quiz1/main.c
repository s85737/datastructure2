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
#include "AVLexam.h"
#define RandBig() (rand()*rand())

//100만개 150만개 200만게 계속해서 증가



int main(int argc, const char * argv[]) {
    
    unsigned int whatTime;
    double duration;
    clock_t t0, t1;
    printf("난수발생 횟수 입력 : ");
    scanf("%d", &whatTime);
    srand((unsigned int)time(NULL));
    
    printf("BSTree Insert and Search\n ");
    
    TreeNode* root = NULL;
    
    for(int i = 1; i < 21; i++){
        printf("%d회 생성", (whatTime * i));
        
        t0 = clock();
        for(int j = 0; j < whatTime * i; j++) root = insertNode(root, RandBig()); // 정해진 횟수 * i 번 만큼 삽입 최대 20배 높은 수만큼 삽입
        t1 = clock();
        duration = (double)(t1-t0) / (CLOCKS_PER_SEC);
        printf("\t\t%d회 insert", (whatTime * i));
        printf("\t%lf초", duration);
        
        
        duration = BSTSrchAvgTime(root, whatTime, 100000);
        printf("\t\tsearch", (whatTime * i));
        printf("\t%lf초 \n\n", duration);
        free(root); //정해진 insert가 다 끝나면 처음부터 다시 삽입하기 위해 root 초기화
        root = NULL;
        
    }
    
    
    printf("AVL Insert and Search\n ");
    
    Node* AVLroot = NULL;
    
    for(int i = 1; i < 21; i++){
        printf("%d회 생성", (whatTime * i));
        
        t0 = clock();
        for(int j = 0; j < whatTime * i; j++) AVLroot = AVLinsert(AVLroot, RandBig()); // 정해진 횟수 * i 번 만큼 삽입 최대 20배 높은 수만큼 삽입
        t1 = clock();
        duration = (double)(t1-t0) / (CLOCKS_PER_SEC);
        printf("\t\t%d회 insert", (whatTime * i));
        printf("\t%lf초", duration);
        
        
        duration = AVLSrchAvgTime(AVLroot, whatTime, 100000);
        printf("\t\tsearch", (whatTime * i));
        printf("\t%lf초 \n\n", duration);
        //정해진 insert가 다 끝나면 처음부터 다시 삽입하기 위해 root 초기화
        root = NULL;
        
    }
    
    
    
    
    return 0;
}

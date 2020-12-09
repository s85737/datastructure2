//
//  main.c
//  swap
//
//  Created by 최제현 on 2020/12/04.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    
    int temp;

    
    temp = *a;
    *a = *b;
    *b = temp;
    
}


int main(int argc, const char * argv[]) {
    
    int a =1;
    int b =2;
    

    swap(&a,&b);
    
    fprintf(stdout, "a : %d, b :%d \n",a ,b);
    
    
    return 0;
}

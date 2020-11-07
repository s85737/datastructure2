//
//  stack.h
//  stack.queue 복습
//
//  Created by 최제현 on 2020/11/05.
//

#ifndef stack_h
#define stack_h

#include <stdlib.h>

typedef int element;

typedef struct stackNode{
    
    element data;
    struct stackNode* link;
    
    
}stackNode;

stackNode** createStack(){
    return NULL;
}

int stackEmptycheck(stackNode* top){
    if(top == NULL) return 1;
    else return 0;
}


element stackPop(stackNode** top){
    
    element data;
    stackNode** temp;
    
    if(stackEmptycheck(*top))
    {
        fprintf(stderr, "stack empty error!\n");
    }
    
    temp = *top;
    data = (*top) -> data;
    *top = (*top) -> link;
    free(temp);
    
    return data;
}

void stackPush(stackNode** top, element data){
    
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    
    newNode -> data = data;
    newNode -> link = *top;
    *top = newNode;
    
}

void printStack(stackNode** top){
    
    stackNode* stack = *top;
    
    printf("\n stack [top- ");
    while(stack){
        printf("%d ", stack->data);
        stack = stack -> link;
    }
    printf("]\n");
}



#endif /* stack_h */

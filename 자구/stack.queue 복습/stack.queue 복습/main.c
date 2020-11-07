//
//  main.c
//  stack.queue 복습
//
//  Created by 최제현 on 2020/11/05.
//

#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main(int argc, const char * argv[]) {
    stackNode* top = createStack();
    element data;
    
    stackPush(&top, 12);
    stackPush(&top, 1);
    stackPush(&top, 2);
    stackPush(&top, 3);
    stackPush(&top, 4);
    
    printStack(&top);
    
    data = stackPop(&top);
    printf("\n pop :: %d \n", data);
    data = stackPop(&top);
    printf("\n pop :: %d \n", data);
    
    printStack(&top);
    

    queueSub* queueSub = NULL;
    queueSub = createQueueSub(queueSub);
    
    enqueue(queueSub, 10);
    enqueue(queueSub, 11);
    enqueue(queueSub, 12);
    enqueue(queueSub, 13);
    printQueue(queueSub);
    
    data = dequeue(queueSub);
    printf("\n dequeue :: %d \n", data);
    data = dequeue(queueSub);
    printf("\n dequeue :: %d \n", data);
    printQueue(queueSub);
    
        return 0;
}

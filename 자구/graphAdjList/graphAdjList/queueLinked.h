//
//  queueLinked.h
//  graphAdjList
//
//  Created by 최제현 on 2020/12/01.
//

#ifndef queueLinked_h
#define queueLinked_h

typedef int element;

typedef struct queueSub{
    
    struct queueNode* front;
    struct queueNode* rear;
    
}queueSub;

typedef struct queueNode{
    
    element data;
    struct queueNode* rLink;
    struct queueNode* lLink;
    
}queueNode;

int isQueueEmpty(queueSub* queue){
    if(!(queue -> front)) return 1;
    else return 0;
}

queueSub* createQueueSub(){
    
    queueSub* queue = (queueSub*)malloc(sizeof(queueSub));
    
    queue -> front = NULL;
    queue -> rear = NULL;
    
    return queue;
    
}

void linkedEnqueue(queueSub* queue, element data){
    
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    
    newNode -> data = data;
    
    if(queue -> rear == NULL)
    {
        newNode -> rLink = NULL;
        queue -> front = newNode;
        queue -> rear = newNode;
    }
    else
    {
        newNode -> rLink = queue -> rear;
        queue -> rear -> lLink = newNode;
        queue -> rear = newNode;
    }
    
}

element linkedDequeue(queueSub* queue){
    
    queueNode* temp = queue -> front;
    
    element data;
    
    if(queue -> front == queue -> rear)
    {
        data = queue -> front -> data;
        queue -> front = NULL;
        queue -> rear = NULL;
        free(temp);
    }
    else
    {
        
        data = queue -> front -> data;
        queue -> front = queue -> front -> lLink;
        queue -> front -> rLink = NULL;
        if(queue -> front == NULL) queue -> rear = NULL;
        free(temp);
    }
    
    return data;
}

#endif /* queueLinked_h */

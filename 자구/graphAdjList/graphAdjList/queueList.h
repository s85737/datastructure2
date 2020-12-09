//
//  queueList.h
//  graphAdjList
//
//  Created by 최제현 on 2020/12/01.
//

#ifndef queueList_h
#define queueList_h



#define TRUE 1
#define FALSE 2
#define MAX_VERTICES 10
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct QueueType{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;


void queue_init(QueueType* q)
{
    q -> front = q -> rear = 0;
}

int is_empty(QueueType* q)
{
    return (q -> front == q -> rear);
}

int is_full(QueueType* q)
{
    return ((q -> rear + 1) % MAX_QUEUE_SIZE == q-> front);
}

void arrayEnqueue(QueueType* q, element item)
{
    if (is_full(q))
    {
        fprintf(stderr, "큐가 포화 상태입니다.\n");
        exit(1);
    }
        
    q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    q -> queue[q -> rear] = item;
}

element arrayDequeue(QueueType *q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "큐가 공백 상태입니다.\n");
        exit(1);
    }
    
    q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
    return q -> queue[q -> front];
}
#endif /* queueList_h */

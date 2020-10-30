//
//  main.c
//  postorder traversal
//
//  Created by 최제현 on 2020/10/01.
//  Copyright © 2020 5468107최제현. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct treeNode{
    element data;
    struct treeNode* rLink;
    struct treeNode* lLink;
}treeNode;

typedef struct stackNode{
    treeNode* data;
    struct stackNode* link;
}stackNode;

typedef struct queueNode{
    treeNode* data;
    struct queueNode* rLink;
    struct queueNode* lLink;
}queueNode;

typedef struct queueSub{
    struct queueNode* front;
    struct queueNode* rear;
}queueSub;

queueSub* createQueue(queueSub* queue){
    
    queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
    queue = (queueSub*)malloc(sizeof(queueSub));
    
    queue -> rear = NULL;
    queue -> front = NULL;
    
    return queue;
    
}

int isQueueNodeEmpty(queueSub* queue){
    
    if(queue -> front == NULL) return 1;
    else return 0;
        
}

void enqueue(queueSub* queue, element data){
    
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    
    newNode -> data = data;
    newNode -> lLink = NULL;
    if(queue -> rear != NULL) //새로운 노드를 삽입할 때 rear쪽에 삽입
    {
        newNode -> rLink = queue -> rear;
        queue -> rear -> lLink = newNode;
        queue -> rear = newNode;
    }
    
    if(queue -> rear == NULL && queue -> front == NULL){
        newNode -> rLink = NULL;
        queue -> rear = newNode;
        queue -> front = newNode;
    }
    
}

void dequeue(queueSub* queue){
    
    queueNode* temp = queue -> front;
    element tempData = 0;
    
    if(queue -> front == queue -> rear){
        
        tempData = queue -> front -> data;
        queue -> front = NULL;
        queue -> rear = NULL;
        free(temp);
    }else {
        tempData = queue -> front -> data;
        queue -> front = queue -> front -> lLink;
        queue -> front -> rLink = NULL;
        
        
    }
    
    
}

stackNode* createStack(){
    return NULL;
}

treeNode* stackPeek(stackNode** top) {
    if(*top == NULL){
        printf("\nstack is empty!\n");
        exit(1);
    }
    
    return ((*top) -> data);
    
}

void stackPush(stackNode** top, treeNode* data) {
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    
    if(!newNode){
        fprintf(stderr,"malloc error!");
        exit(-1);
    }
    
    newNode -> data = data;
    newNode -> link = *top;
    *top = newNode;
}
int isStackEmpty(stackNode** top) {
    
    if(top == NULL) return 1;
    else return 0;
    
}

treeNode* stackPop(stackNode** top) {
    
    treeNode* data;
    stackNode** temp;
    
    if(isStackEmpty(*top)){
        printf("stack is empty");
    }
    
    temp = *top;
    data = (*top) -> data;
    *top = (*top) -> link;
    
    free(temp);
    
    return data;
    
}

treeNode* createNode(element data){
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    
    newNode -> lLink = NULL;
    newNode -> rLink = NULL;
    newNode -> data = data;
    return newNode;
    
}

void makeTree(treeNode* parent, treeNode* lSon, treeNode* rSon){
    
    parent -> rLink = rSon;
    parent -> lLink = lSon;
    
}

void postOrder(treeNode* root){
    stackNode* top = createStack();
    
    printf("postorder traversal! -> ");
    stackPush(&top, root); //최종적으로 출력될 root 노드 스택에 추가
    while(1){
        while(root){ // 자식노드가 더 이상 없을 때 까지 탐색
            
            //왼쪽 자식노드 탐색
            if(root -> rLink) stackPush(&top, root -> rLink); //왼쪽으로 내려가면서 탐색을 한다.
            stackPush(&top, root); // 내려가기 전 부모노드의 오른쪽 노드를 저장하면서 내려간다, 오른쪽 자식노드도 탐색
            root = root-> lLink;
        }
        
        
        
        // 왼쪽으로 탐색하며 자식노드가 더 이상 없을 때
        
        root = stackPop(&top);
        
         // 오른쪽 자식노드 탐색
        if(root -> rLink && stackPeek(&top) == root -> rLink) { // 왼쪽 맨 아래 노드의 부모노드로 왔을 때, 오른쪽 노드와 스택에 저장된것이 같은지 check
            stackPop(&top); //같다면 오른쪽 노드를 스택에서 제거
            stackPush(&top, root); // 다시 부모노드 스택에 추가
            root = root -> rLink; // 오른쪽 자식노드 탐색
        }else{
            printf("%d ", root -> data); //스택 출력
            root = NULL;
        }
    }

    
}


void levelOrder(treeNode* root){
    
    queueSub* queue;
    queue = createQueue(queue);
    
    if(root == NULL) return;
    enqueue(queue, root);
    while(!isQueueNodeEmpty(queue)){
        dequeue(queue);
        printf("[%d]",root->data);
        if(root -> lLink) enqueue(queue, root -> lLink);
        if(root -> rLink) enqueue(queue, root -> rLink);
    }
    
    
}

int main(int argc, const char * argv[]) {
 
    
    stackNode* top;
    treeNode* n1 = createNode(1);
    treeNode* n2 = createNode(2);
    treeNode* n3 = createNode(3);
    treeNode* n4 = createNode(4);
    treeNode* n5 = createNode(5);
    treeNode* n6 = createNode(6);
    treeNode* n7 = createNode(7);
    makeTree(n1, n2, n3);
    makeTree(n2, n4, n5);
    makeTree(n3, n6, n7);
//    postOrder(n1);
    levelOrder(n1);
    
    return 0;
}

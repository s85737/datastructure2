//
//  main.c
//  AVLtree
//
//  Created by 최제현 on 2020/10/07.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a)

//AVL 노드 정의
typedef struct AVLNode{
    int data;
    struct AVLNode *left;
    struct AVLNode * right;
}AVLNode;


//트리 높이 계산

int getHeight(AVLNode* node){
    int height = 0;
    if (node)
        height = 1 + MAX(getHeight(node -> left), getHeight(node -> right));
    
    return height;
}

int getBalance(AVLNode* node){
    if (node == NULL)
        return 0;
 
    return getHeight(node -> left) - getHeight(node -> right);

}

// 노드를 동적으로 생성하는 함수
AVLNode* createNode(int key){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    
    node -> data = key;
    node -> right = NULL;
    node -> left = NULL;
    return node;
}

//오른쪽으로 회전시키는 함수
AVLNode* rotateRight(AVLNode* parent){
    AVLNode* child = parent -> left;
    parent -> left = child -> right;
    child -> right = parent;
    
    return child;
}


AVLNode* rotateLeft(AVLNode* parent){
    AVLNode* child = parent -> right;
    parent -> right = child -> left;
    child -> left = parent;
    
    return child;
    
}

//AVL 트리에 새로운 노드 추가 함수
//새로운 루트를 반환한다.

AVLNode* insert(AVLNode* node, int key){
    // 이진 탁색 트리의 노드 추가 수행
    
    if(node == NULL) return(createNode(key));
    
    if(key < node -> data)
        node -> left = insert(node->left,key);
    else if (key > node -> data)
        node -> right = insert(node -> right, key);
    else return node;//동일 키는 허용하지 않음
        
    

    int balance = getBalance(node);
    
    //LL 타입 처리
    if(balance > 1 && key < node -> left -> data)
        return rotateRight(node);
    
    //RR 타입 처리
    if (balance < -1 && key > node -> right -> data)
        return rotateLeft(node);
    
    
    //LR 타입 처리
    if (balance > 1 && key > node -> left -> data){
        node -> left = rotateLeft(node -> left);
        return rotateRight(node);
    }
    
    //RL 타입 처리
    if(balance < -1 && key < node -> right -> data){
        node -> right = rotateRight(node -> right);
        return rotateLeft(node);
    }
    
    return node;
}

void inOrder(AVLNode* root){
    
    
    
    if (root){
        inOrder(root -> left);
        printf("[%d] ", root -> data);
        inOrder(root -> right);
    }
}

//AVLNode* delete(AVLNode* node, int data){
//
//    AVLNode temp;
//
//    if(node = NULL) printf("Element not there in tree\n");
//    else if(data < node -> data) node -> left =
//
//
//}


int main(int argc, const char * argv[]) {
    
    AVLNode* root = NULL;
    
    root = insert(root, 60);
    root = insert(root, 50);
    root = insert(root, 90);
    root = insert(root, 30);
    root = insert(root, 80);
    
    printf("이진 탐색 트리 순회 결과 \n");
    inOrder(root);
    printf("\n\n");
    
    root = insert(root, 70);
    inOrder(root);
    printf("\n\n");
    
    return 0;
}

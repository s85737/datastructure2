//
//  AVLNode.h
//  quiz1
//
//  Created by 최제현 on 2020/10/31.
//

#ifndef AVLNode_h
#define AVLNode_h

#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a > b) ? a : b)





//AVL 노드 정의
typedef struct AVLNode{
    int data;
    struct AVLNode *left;
    struct AVLNode * right;
    int height;
}AVLNode;

// 노드를 동적으로 생성하는 함수
AVLNode* createNode(int data){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    
    node -> data = data;
    node -> right = NULL;
    node -> left = NULL;
    node -> height = 1;
    return node;
}

int getHeight(AVLNode* root){
    if(!root) return 0;
    else return root -> height;
}


//오른쪽으로 회전시키는 함수
AVLNode* rotateLeft(AVLNode* parent){
    
    
    AVLNode* child = parent -> right;
    AVLNode* childLeft = child -> left;
    
    child -> left = parent;
    parent -> right = childLeft;
   
    
    
    parent -> height = MAX(getHeight(parent -> left), getHeight(parent -> right)) + 1;
    child -> height = MAX(getHeight(child -> left), getHeight(parent -> right)) + 1;
    
    return child;
}


AVLNode* rotateRight(AVLNode* parent){
    AVLNode* child = parent -> left;
    AVLNode* childRight = child -> right;
    
    child -> right = parent;
    parent -> left = childRight;
    
    
    parent -> height = MAX(getHeight(parent -> left), getHeight(parent -> right)) + 1;
    child -> height = MAX(getHeight(child -> left), getHeight(parent -> right)) + 1;
    
    
    return child;
    
}


AVLNode* doubleRotateLeftRight(AVLNode* node){

     node -> left = rotateLeft(node -> left);
    return rotateRight(node);
}

AVLNode* doubleRotateRightLeft(AVLNode* node){
   
    node -> right = rotateLeft(node -> right);
    return rotateRight(node);
}






//
//AVLNode* balance(AVLNode* node){
//
//    int differ = getDifferent(node);
//    if (differ >= 2)
//    {
//        if(getDifferent(node -> left) >= 1)
//        {
//            node = rotateLeft(node);
//        }
//        else
//        {
//            node = doubleRotateLeftRight(node);
//        }
//    }
//    else if(differ <= -2)
//    {
//        if (getDifferent(node -> right) <= -1)
//        {
//            node = rotateRight(node);
//        }
//        else
//        {
//            node = doubleRotateRightLeft(node);
//        }
//    }
//    setHeight(node);
//    return node;
//
//}

int getDifferent(AVLNode* node){
    if(node == NULL) return 0;
    AVLNode* left = node -> left;
    AVLNode* right = node -> right;
    return getHeight(left) - getHeight(right);
}
//AVL 트리에 새로운 노드 추가 함수
//새로운 루트를 반환한다.

AVLNode* insertAVL(AVLNode* node, int data){
    
    if(!node)
    {
        return(newNode(data));
    }
    
    if (data < node -> data) node -> left = insertAVL(node -> left, data);
    else if (data > node -> data) node -> right = insertAVL(node -> right, data);
    else return node;
    
    node -> height = 1 + MAX(getHeight(node -> left), getHeight(node -> right));
    
    int different = getDifferent(node);
    
    if (different > 1 && data < node -> left -> data) return rotateRight(node);
    
    if (different < -1 && data > node -> right -> data) return rotateLeft(node);
    
    if (different > 1 && data > node -> left -> data)
    {
        return doubleRotateLeftRight(node);
    }
    
    if ( different < -1 && data < node -> right -> data)
    {
        return doubleRotateRightLeft(node);
    }
    
    
    
    return node;
        

}





AVLNode* AVLSearch(AVLNode* node, int key){
    if (node == NULL) return NULL;
    if (key == node -> data) return node;
    else if (key < node -> data) return AVLSearch(node -> right, key);
    else return AVLSearch(node -> left, key);
}

double AVLSrchAvgTime(AVLNode* root, int n, int iter){
    int i;
    clock_t t0, t1;
    t0 = clock();
    for(i = 0; i < iter; i++) AVLSearch(root, RandBig());
    t1 = clock();
    return (double)(t1-t0) / (CLOCKS_PER_SEC * iter);
}

#endif /* AVLNode_h */

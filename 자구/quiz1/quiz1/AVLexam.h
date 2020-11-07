//
//  AVLexam.h
//  quiz1
//
//  Created by 최제현 on 2020/10/31.
//

#ifndef AVLexam_h
#define AVLexam_h

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}Node;


// 해당 노드의 높이를 return
int height(Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}


Node* AVLnewNode(int key)
{
    Node* node = (Node*)
                        malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

//오른쪽으로 회전
Node* rightRotate(Node* node)
{
    Node* leftChild = node->left;
    Node* childRight = leftChild->right;

    
    leftChild->right = node;
    node->left = childRight;

   
    node->height = max(height(node->left), height(node->right))+1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right))+1;

   
    return leftChild;
}

//왼쪽으로 회전
Node* leftRotate(Node *node)
{
    Node*  rightChild= node->right;
    Node* childLeft = rightChild->left;

   
    rightChild->left = node;
    node->right = childLeft;

   
    node->height = max(height(node->left), height(node->right))+1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right))+1;

   
    return rightChild;
}

// 높이 차이 계산
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLinsert(Node* node, int key)
{
   
    if (node == NULL)
        return(AVLnewNode(key));

    if (key < node->key)
        node->left = AVLinsert(node->left, key);
    else if (key > node->key)
        node->right = AVLinsert(node->right, key);
    else
        return node;

  //높이 업데이트
    node->height = 1 + max(height(node->left),
                        height(node->right));


    int balance = getBalance(node);

    //LL 회전
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

   //RR 회전
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    //LR 회전
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RL회전
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}

//AVL 트리 검색
Node* AVLSearch(Node* node, int key){
    if (node == NULL) return NULL;
    if (key == node -> key) return node;
    else if (key < node -> key) return AVLSearch(node -> right, key);
    else return AVLSearch(node -> left, key);
}

double AVLSrchAvgTime(Node* root, int n, int iter){
    int i;
    clock_t t0, t1;
    t0 = clock();
    for(i = 0; i < iter; i++) AVLSearch(root, RandBig());
    t1 = clock();
    return (double)(t1-t0) / (CLOCKS_PER_SEC * iter);
}
#endif /* AVLexam_h */

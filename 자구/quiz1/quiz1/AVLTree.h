//
//  AVLTree.h
//  quiz1
//
//  Created by 최제현 on 2020/11/01.
//

#ifndef AVLTree_h
#define AVLTree_h


#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

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
    node -> height = 0;
    return node;
}

int getHeight(AVLNode* root){
    if(!root) return -1;
    else return root -> height;
}

//오른쪽으로 회전시키는 함수
AVLNode* rotateRight(AVLNode* parent){
    AVLNode* child = parent -> right;
    parent -> right = child -> left;
    child -> left = parent;
    parent -> height = MAX(getHeight(parent -> left), getHeight(parent -> right)) + 1;
    child -> height = MAX(getHeight(child -> left), getHeight(parent -> right)) + 1;
    
    return child;
}


AVLNode* rotateLeft(AVLNode* parent){
    AVLNode* child = parent -> left;
    parent -> left = child -> right;
    child -> right = parent;
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


//AVL 트리에 새로운 노드 추가 함수
//새로운 루트를 반환한다.

AVLNode* insert(AVLNode* node, int data){
    
    if(!node){
    node = createNode(data);
    }
    else if (data < node -> data){
        node -> left = insert(node -> left, data);
        if ((getHeight(node -> left) - getHeight(node -> right)) == 2){
            if(data < node -> left -> data) node = rotateLeft(node);
            else node = doubleRotateLeftRight(node);
        }
        
    }
    
    else if (data > node -> data){
        node -> right = insert (node -> right, data);
        if ((getHeight(node -> right) - (getHeight(node -> left))) == 2){
            if(data > node -> right -> data) node = rotateRight(node);
            else node = doubleRotateRightLeft(node);
        }
    }
    
    node -> height = MAX(getHeight(node -> left), getHeight(node -> right)) + 1;
    
    return node;
        

}

AVLNode* maxValueNode(AVLNode* node){
    AVLNode* current = node;
    
    while(current -> right != NULL) current = current -> right;
    
    return current;
}

void inOrder(AVLNode* root){
    
    
    
    if (root){
        inOrder(root -> left);
        printf("[%d] ", root -> data);
        inOrder(root -> right);
    }
}

int getBalance(AVLNode* node){
    if (node == NULL)
        return 0;
 
    return getHeight(node -> left) - getHeight(node -> right);

}



AVLNode* delete(AVLNode* node, int data){

    AVLNode* temp;
    

    if(node == NULL) printf("Element not there in tree\n");
    else if(data < node -> data) {
        node -> left = delete(node -> left, data);
        node -> height = MAX(getHeight(node -> left), getHeight(node -> right)) +1; //현제 높이 값 최신화
    }
    else if(data > node -> data){
        node -> right = delete(node -> right, data);
        node -> height = MAX(getHeight(node -> left), getHeight(node -> right)) +1;
    }
    else{ //일치하는 data 탐색성공시
        if(node -> left && node -> right){
            temp = maxValueNode(node -> left); //왼쪽 중 가장 큰것 넘겨줌
            node -> data = temp -> data;
            node -> left = delete(node -> left, node -> data);
    }
        else {
            
            temp = node;
            if(node -> left == NULL)node = node -> right;
            else if(node -> right == NULL) node = node -> left;
            free(temp);
            
        }
}
    // 삭제까진 BST와 동일하다. 다음은 균형을 맞추기 위해 연산을 시작한다.
    
    //node 가 null 이면 return
        if(node == NULL) return node;
    
    //LL 타입
        if (getHeight(node) > 1 && getBalance(node->left) >= 0)
            node = rotateRight(node);
    //LR 타입
        if (getHeight(node) > 1 && getBalance(node->left) < 0)
            node = doubleRotateLeftRight(node);
    //RR 타입
        if (getHeight(node) < -1 && getBalance(node->right) <= 0)
            node = rotateLeft(node);
    //RL 타입
        if(getHeight(node) < -1 && getBalance(node->right) > 0)
            node = doubleRotateRightLeft(node);
    
    return node;

}
    

#endif /* AVLTree_h */

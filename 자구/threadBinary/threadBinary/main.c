//
//  main.c
//  threadBinary
//
//  Created by 최제현 on 2020/10/07.
//

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct TreeNode {
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
    int isTread;
}TreeNode;

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode* example = &n7;


TreeNode* findSuccessor(TreeNode* p){
    
    TreeNode* q = p -> right;
    
    if(q == NULL || p -> isTread == TRUE) return q;
    
    while ( q->left != NULL ) q = q->left;
    return q;
}

void threadInorder(TreeNode* t){
    TreeNode* q;
    
    q = t;
    while(q->left) q = q->left;
    do{
        printf("%c -> ", q->data);
        q = findSuccessor(q);
        
    }while(q);
    
}




int main(int argc, const char * argv[]) {
   
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;
    

    threadInorder(example);
    
    printf("\n");

    
    return 0;
}

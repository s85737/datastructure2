//
//  treeNode.h
//  quiz1
//
//  Created by 최제현 on 2020/10/21.
//

#ifndef treeNode_h
#define treeNode_h

typedef int element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* newNode(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
    
}
TreeNode* treeSearch(TreeNode* node, int key){
    if (node == NULL) return NULL;
    if (key == node -> key) return node;
    else if (key < node -> key) return treeSearch(node -> right, key);
    else return treeSearch(node -> left, key);
}

TreeNode* insertNode(TreeNode* node, int key){
    //트리가 공백이면 새로운 노드 반환
    if (node == NULL) return newNode(key);
    
    //그렇지 않으면 순환적으로 트리를 내려간다.
    if(key < node -> key) node -> left = insertNode(node-> left, key);
    else if(key > node -> key) node -> right = insertNode(node -> right, key);
    
    return node;
}


#endif /* treeNode_h */

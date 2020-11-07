//
//  treeNode.h
//  quiz1
//
//  Created by 최제현 on 2020/10/21.
//

#ifndef treeNode_h
#define treeNode_h
#define RandBig() (rand()*rand())

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

double BSTSrchAvgTime(TreeNode* root, int n, int iter){
    int i;
    clock_t t0, t1;
    t0 = clock();
    for(i = 0; i < iter; i++) treeSearch(root, RandBig());
    t1 = clock();
    return (double)(t1-t0) / (CLOCKS_PER_SEC * iter);
}


#endif /* treeNode_h */

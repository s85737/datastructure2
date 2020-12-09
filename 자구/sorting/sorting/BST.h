//
//  BST.h
//  sorting
//
//  Created by 최제현 on 2020/12/06.
//

#ifndef BST_h
#define BST_h

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* search(TreeNode* node, int key){
    if (node == NULL) return NULL;
    if (key == node -> key) return node;
    else if (key < node -> key) return search(node -> right, key);
    else return search(node -> left, key);
}

TreeNode* newNode(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
    
}

TreeNode* insertNode(TreeNode* node, int key){
    //트리가 공백이면 새로운 노드 반환
    if (node == NULL) return newNode(key);
    
    //그렇지 않으면 순환적으로 트리를 내려간다.
    if(key < node -> key) node -> left = insertNode(node-> left, key);
    else if(key > node -> key) node -> right = insertNode(node -> right, key);
    
    return node;
}

TreeNode* minValueNode(TreeNode* node){
    TreeNode* current = node;
    
    //맨 왼쪽 단말 노드를 찾으러 내려감
    
    while(current -> left != NULL) current = current -> left;
    
    return current;
}

TreeNode* maxValueNode(TreeNode* node){
    TreeNode* current = node;
    
    //맨 오른쪽 단말 노드를 찾으러 내려감
    
    while(current -> right != NULL) current = current -> right;
    
    return current;
}

//TreeNode* deleteNode (TreeNode* root, int key){
//    if (root == NULL) return root;
//
//    //만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는거임
//    if(key < root -> key) deleteNode(root -> right, key);
//    else if(key > root -> key) deleteNode(root -> left, key);
//    // 키가 루트와 같으면 이 노드를 삭제하면 됨
//    else {
//        //첫 번째나 두 번째 경우
//
//        if(root -> left = NULL){
//            TreeNode* temp = root->right;
//            free(root);
//            return temp;
//        } else if (root -> right == NULL) {
//            TreeNode* temp = root->left;
//            free(root);
//            return temp;
//        }
//        //세번째 경우
//        TreeNode* temp = minValueNode(root->right);
//        //중외 순회시 후계 노드 복사
//        root -> key = temp -> key;
//        //중외 순회시 후계 노드 삭제
//        root -> right  = deleteNode(root->right, temp -> key);
//    }
//    return root;
//}

TreeNode* delete(TreeNode* root, int key){
    
    TreeNode* temp;
    
    //data의 위치 검색
    
    if(root == NULL) printf("element is not in tree\n");
    else if(key < root -> key) root -> left = delete(root->left, key);
    else if(key > root -> key) root -> right = delete(root->right, key);
    else {
        //자식이 2개인 경우 왼쪽 서브트리의 최대값과 교체한다.
        if(root -> left && root-> left) {
            temp = maxValueNode(root -> left);
            root -> key = temp -> key;
            temp -> left = delete(root -> left, root -> key);
        }
        else { // 자식이 하나 또는 없는 경우
            
            temp = root;
            if (root -> left == NULL) root = root -> right;
            else if(root -> right == NULL) root = root -> left;
            free(temp);
        }
    }
    return root;
    
    
    
}

void inorder(TreeNode* root){
    if(root) {
        inorder(root -> left); //왼쪽 서브트리 순회
        printf("[%d]", root -> key);
        inorder(root -> right); //오른쪽 서브트리 순회
    }
}

void testBST(){
    TreeNode* root = NULL;
    TreeNode* temp = NULL;
    
    root = insertNode(root, 90);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
   
    root = delete(root, 40);
    
    printf("이진 탐색 트리 중위 순회 결과\n");
    
    inorder(root);
    
    printf("\n\n");
    
    if(search(root, 30) != NULL)
        printf("이진 탐색 트리에서 30을 발견함 \n");
    else
        printf("이진 탐색 트리에서 30을 발견못함 \n");
}

#endif /* BST_h */

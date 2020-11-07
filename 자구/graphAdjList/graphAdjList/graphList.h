//
//  graphList.h
//  graphAdjList
//
//  Created by 최제현 on 2020/11/07.
//

#ifndef graphList_h
#define graphList_h

typedef struct graphNode{
    int vertex;
    struct graphNode* link;
}graphNode;

typedef struct Graph {
    int V;
    int E;
    struct graphNode** Adj;
}Graph;



Graph* adjList(int v, int e) {
    
    Graph* G = (Graph*)malloc(sizeof(Graph*));
    
    G -> V = v;
    G -> E = e;
    G -> Adj = (graphNode**)malloc(G -> V * sizeof(graphNode));
    
    for(int i = 0; i < G -> V; i++)
    {
        G -> Adj[i] = (graphNode*)malloc(sizeof(graphNode));
        G -> Adj[i] -> vertex = i;
        G -> Adj[i] -> link = NULL;
    }
    
    return G;

}

Graph* insertNode(Graph* G){
    
    graphNode* temp;
    int u, v;
    for (int i = 0; i < G -> E; i++)
    {
        printf("\n Reading Edges [%d] (u, v) : ", i+1);
        scanf("%d %d", &u, &v);
        
        if(u >= G -> V || v >= G -> V)
        {
            printf("No such vertex!!\n");
            exit(0);
        }
        
        temp = (graphNode*)malloc(sizeof(graphNode));
        temp -> vertex = v;
        temp -> link = G -> Adj[u] -> link;
        G -> Adj[u] -> link = temp;
        
    }
    
    return G;
}

Graph* insertDirect(Graph* G, int u, int v){
    graphNode* temp;
    
    if (u >= G -> V || v >= G -> V){
        printf(" No such vertex!!\n");
        exit(0);
    }
    
    temp = (graphNode*)malloc(sizeof(graphNode));
    temp -> vertex = v;
    temp -> link = G -> Adj[u] -> link;
    G -> Adj[u] -> link = temp;
    
    return G;
    
    
}

void deleteList(Graph** G){
    graphNode* auxiliaryNode, *iterator;
    
    for(int i =0; i < (*G) -> V; i++)
    {
        printf("삭제할 adjacency List : Adj[%d]\n", i);
        auxiliaryNode = (*G) -> Adj[i];
        iterator = auxiliaryNode;
        
        while(iterator != NULL) //edge 삭제 iterator가 모든 노드를 거쳐가며 free실행
        {
            printf("삭제 데이터 : %d\n", iterator -> vertex);
            auxiliaryNode = iterator -> link;
            free(iterator);
            iterator = auxiliaryNode;
        }
    }
    free((*G) -> Adj); //adjance list 삭제
    free(*G); // graph 삭제
    *G = NULL;

}

void printAdjList(Graph* G){
    printf("\n Adjacency List of Graph\n");
    if(G == NULL)
    {
        fprintf(stderr,"\nNo Such Graph!\n");
        return;
    }
    for (int i = 0; i < G -> V; i++){
        
        graphNode* head = G -> Adj[i];
        
        for (graphNode* p = head; p!= NULL; p = p -> link)
            printf(" %d ->", p -> vertex);
        
        printf(" NULL \n");
        
    }
    
}

#endif /* graphList_h */

//
//  adjMatrix.h
//  graphAdjList
//
//  Created by 최제현 on 2020/12/01.
//

#ifndef adjMatrix_h
#define adjMatrix_h
#include "queueLinked.h"
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct GraphMatrix {
    int V;
    int E;
    int** Adj;
}GraphMatrix;

GraphMatrix* adjMatrix(int v, int e){
    
    GraphMatrix* G = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    
    if(!G)
    {
        printf("Memory Error");
        exit(1);
    }
    
    G -> V = v;
    G -> E = e;
    G -> Adj = NULL;
    
    G -> Adj = (int**)malloc(sizeof(int*) * G -> V);
    for (int i = 0; i < G -> V; i++)
    G -> Adj[i] = malloc(sizeof(int) * G -> V);
    
    for (int i = 0; i < G -> V; i++)
        for (int j = 0; j < G -> V; j++)
            G -> Adj[i][j] = 0;
    
    return G;
}

GraphMatrix* insertMatDirect(GraphMatrix* G){
    
    int u, v;
    FILE* openFile = fopen("/Users/s85737/Documents/2020 2학ㄱ/2학기/자구/graphAdjList/graphAdjList/insert.txt", "rt");
    
    for (int i = 0; i < G -> E; i++)
    {
        printf("\n Reading Edge %d (u, v) : ", i + 1);
        fscanf(openFile, "%d %d",&u ,&v);
        
        if(u >= G -> V || v >= G -> V)
        {
            printf("No such vertex!!");
            exit(0);
        }
        
        G -> Adj[u][v] = 1;
    }
    fclose(openFile);
    return G;
}

void deleteMatrix(GraphMatrix* G)
{
    for (int i =0; i < G -> V; i++)
        free(G->Adj[i]);
    
    free(G -> Adj);
    free(G);
}

void printAdjMat(GraphMatrix* G)
{
    if(G -> Adj == NULL)
    {
        printf("No Matrix Exist!\n");
        return;
    }
    
    printf("\n Adjacency MAtrix of Direct Graph \n");
    for (int u = 0; u < G -> V; u++)
    {
        for (int v = 0; v < G -> V; v++){
            printf("%2d ", G -> Adj[u][v]);
        }
        printf("\n");
    }
}

int Visited[MAX_VERTICES];

void DFSMat(GraphMatrix* G, int u){
    
    Visited[u] = 1;
    
    printf("vertex %d -> ", u);
    for (int v = 0; v < G -> V; v++)
    {
        if(!Visited[v] && G -> Adj[u][v])
            DFSMat(G, v);
    }
}

void BFSMat(GraphMatrix* G, int u){
    
    int v;
    queueSub* queue = createQueueSub();
    linkedEnqueue(queue, u);
    
    while(!isQueueEmpty(queue))
    {
        u = linkedDequeue(queue);
        printf("Vertex %d -> ", u);
        Visited[u] = 1;
        
        for (v = 0; v < G ->V; v++)
        {
            if(!Visited[v] && G -> Adj[u][v])
                linkedEnqueue(queue, v);
        }
    }
}

void clearVisited(GraphMatrix* G){
    for(int i = 0; i < G -> V; i++)
        Visited[i] = 0;
}


#endif /* adjMatrix_h */

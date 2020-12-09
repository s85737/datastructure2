//
//  quiz_matrix.h
//  graphAdjList
//
//  Created by 최제현 on 2020/12/04.
//

#ifndef quiz_matrix_h
#define quiz_matrix_h
#include "queueLinked.h"
#include <stdio.h>
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

GraphMatrix* insertRandomMat(GraphMatrix* G){
    
    int u, v, count = 0;
    
    for (int i = 0; i < G -> E; i++)
    {
        
        do
        {
            v = rand() % G -> V;
            u = rand() % G -> V;
            
        } while ( u == v);
        
        if(G-> Adj[u][v] == 1)
            printf("Edge (%d, %d) Exist!\n", u, v);
        else{
            G -> Adj[u][v] = 1;
            G -> Adj[v][u] = 1;
            printf("%d 랜덤 edge 삽입 : (%d, %d)\n",count+1 , u, v);
            count++;
        }
        
        
    }
    
    G -> E = count;
    
    printf("정점의 수 : %d\n", G -> V);
    printf("간선의 수 : %d\n ", G -> E);
    
    return G;
}


int BFSVisitedCheck[MAX_VERTICES];
int visitedCheck[MAX_VERTICES][MAX_VERTICES];

void clearVisited(GraphMatrix* G){
    for(int i = 0; i < G -> V; i++)
    BFSVisitedCheck[i] = 0;
}

//모든 간선이 연결 되어있는지 확인하기 위해 BFS 탐색 알고리즘 활용
int connected(GraphMatrix* G){
    
    int v,u=0;
    
    queueSub* queue = createQueueSub();
    linkedEnqueue(queue, u);
    
    //connect를 검사할때 마다 BFS 방문 확인 초기화
    clearVisited(G);
    
    while(!isQueueEmpty(queue))
    {
        u = linkedDequeue(queue);
        BFSVisitedCheck[u] = 1;
        
        for (v = 0; v < G ->V; v++)
        {
            //다른 정점과 연결이 확인되었으면
            if(!BFSVisitedCheck[v] && G -> Adj[u][v])
            {
                linkedEnqueue(queue, v);
                //탐사한 정점 check
                visitedCheck[u][v] = 1;
                visitedCheck[v][u] = 1;
                visitedCheck[u][u] = 1;
            }
            
        }
        
    }

    // 모든 정점을 탐사했는지 check
    
    for(int i = 0; i < G -> V; i++)
    {
        for(int j = 0; j < G -> V; j++)
        {
            if(visitedCheck[i][j] == 0)
                return 0;
        }
    }
    //모두 연결이 되어있을 시
    return 1;
}


GraphMatrix* insertConnectedMat(GraphMatrix* G){
    
    int u, v, count = 0;
    visitedCheck[G->V][G->V] = 1;
    
    while(!connected(G)){
        
        do
        {
            v = rand() % G -> V;
            u = rand() % G -> V;
            
        } while ( u == v);
        //
        if(G-> Adj[u][v] == 1)
            printf("Edge (%d, %d) Exist!\n", u, v);
        else{
            G -> Adj[u][v] = 1;
            G -> Adj[v][u] = 1;
            printf("%d 랜덤 edge 삽입 : (%d, %d)\n",count+1 , u, v);
            count++;
        }
        
        
    }
    
    G -> E = count;
    
    printf("정점의 수 : %d\n", G -> V);
    printf("간선의 수 : %d\n ", G -> E);
    
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



void DFSMat(GraphMatrix* G, int u){
    
    BFSVisitedCheck[u] = 1;
    
    printf("vertex %d -> ", u);
    for (int v = 0; v < G -> V; v++)
    {
        if(!BFSVisitedCheck[v] && G -> Adj[u][v])
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
        BFSVisitedCheck[u] = 1;
        
        for (v = 0; v < G ->V; v++)
        {
            if(!BFSVisitedCheck[v] && G -> Adj[u][v])
                linkedEnqueue(queue, v);
        }
    }
}





#endif /* quiz_matrix_h */

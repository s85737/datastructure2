//
//  main.c
//  quiz2
//
//  Created by 최제현 on 2020/11/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TRUE 1
#define FALSE 2
#define MAX_VERTICES 10
#define MAX_QUEUE_SIZE 10


typedef int element;

typedef struct GraphType{
    
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
    
}GraphType;

typedef struct QueueType{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;


int visited[MAX_VERTICES];

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}


void queue_init(QueueType* q)
{
    q -> front = q -> rear = 0;
}

int is_empty(QueueType* q)
{
    return (q -> front == q -> rear);
}

int is_full(QueueType* q)
{
    return ((q -> rear + 1) % MAX_QUEUE_SIZE == q-> front);
}

void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("큐가 포화 상태입니다.");
    
    q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    q -> queue[q -> rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    
    q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
    return q -> queue[q -> front];
}

void init(GraphType* g){
    int r, c;
    g -> n = 0;
    
    for(r = 0; r < MAX_VERTICES; r++)
    {
        for (c= 0; c < MAX_VERTICES; c++)
        {
            g -> adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g -> n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "그래프 정점 개수 초과");
        return;
    }
    g -> n++;
    
}

// 간선 삽입 연상

void insert_edge(GraphType* g, int start, int end)
{
    if(start >= g -> n || end >= g -> n)
    {
        fprintf(stderr, "그래프 정점 번호 오류");
        return;
    }
    g -> adj_mat[start][end] = 1;
    g -> adj_mat[end][start] = 1;
    
}

// 인접 행렬 출력 하수
void print_adj_mat(GraphType* g)
{
    for (int i =0; i < g -> n; i++)
    {
        for (int j = 0; j < g -> n; j++)
        {
            printf("%2d ", g -> adj_mat[i][j]);
        }
        
        printf("\n");
    }
}

//인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색

void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;
    
    printf("정점 %d -> ", v);
    for (w = 0; w < g -> n; w++)
    {
        if ( g -> adj_mat[v][w] && visited[w])
            dfs_mat(g, w);
    }
    
    
}

void bfs_mat(GraphType* g, int v)
{
    int w;
    QueueType q;
    
    queue_init(&q);
    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while(!is_empty(&q))
    {
        v = dequeue(&q);
        for (w = 0; w < g -> n; w++){
            if (g -> adj_mat[v][w] && !visited[w])
            {
                visited[w] = TRUE;
                printf("%d 방문 -> ", w);
                enqueue(&q, w);
            }
        }
    }
    
}




int main(int argc, const char * argv[]) {
    
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 5; i++)
    insert_vertex(g, i);
    
//    insert_edge(g, 0, 1);
    //    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    //    insert_edge(g, 2, 0);
//    insert_edge(g, 0, 3);
    //    insert_edge(g, 3, 0);
//    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    //    insert_edge(g, 3, 2);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    print_adj_mat(g);
    
    printf("깊이 우선 탐색 \n");
    dfs_mat(g, 0);
    printf("\n");
    printf("너비 우선 탐색 \n");
    bfs_mat(g, 0);
    
    
    
    return 0;
}

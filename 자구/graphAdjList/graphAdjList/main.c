//
//  main.c
//  graphAdjList
//
//  Created by 최제현 on 2020/11/07.
//

#include <stdio.h>
#include <stdlib.h>
#include "graphList.h"

int main(int argc, const char * argv[]) {
  
    
    Graph* myGraph;
    myGraph = (Graph*)malloc(sizeof(Graph));
    myGraph = adjList(4, 5);
    
    insertDirect(myGraph, 0, 1);
    insertDirect(myGraph, 0, 3);
    insertDirect(myGraph, 1, 2);
    insertDirect(myGraph, 2, 0);
    insertDirect(myGraph, 2, 3);
    
    printAdjList(myGraph);
    
    deleteList(&myGraph);
    
    printAdjList(myGraph);
    
    return 0;
}

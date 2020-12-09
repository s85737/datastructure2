//
//  main.c
//  graphAdjList
//
//  Created by 최제현 on 2020/11/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quiz_matrix.h"


int main(int argc, const char * argv[]) {
  
    
    GraphMatrix* myGraph;
    myGraph = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    int vertNumber, edgeNumber = 0;
    srand((unsigned int)time(NULL));

    
    
    vertNumber = rand() % 6 + 5;
    edgeNumber = rand() % 6 + 5;
    
//    myGraph = adjMatrix(vertNumber, edgeNumber);
//
//    insertRandomMat(myGraph);
//
//    printAdjMat(myGraph);
    
    myGraph = adjMatrix(vertNumber, edgeNumber);
    
    insertConnectedMat(myGraph);
    printAdjMat(myGraph);
    
    clearVisited(myGraph);
    printf("깊이우선탐색\n");
    DFSMat(myGraph, 0);
    
    clearVisited(myGraph);
    printf("\n너비우선탐색\n");
    BFSMat(myGraph, 0);
    

    deleteMatrix(myGraph);
    

    
    
    return 0;
}

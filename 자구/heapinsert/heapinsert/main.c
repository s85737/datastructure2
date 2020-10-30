//
//  main.c
//  heapinsert
//
//  Created by 최제현 on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap{
    int* array;
    int count;
    int capacity;
    int heap_type;
}Heap;

Heap* createHeap(int capacity, int heap_type){
    Heap* h = (Heap*)malloc(sizeof(Heap));
    if (h == NULL){
        printf("Memory Error");
        exit(1);
    }
    
    h -> heap_type = heap_type;
    h -> count = 0;
    h -> capacity = capacity;
    h -> array = (int*)malloc(sizeof(int) * h->capacity);
    
    if(h->array == NULL) {
        printf("Memoery Error");
        exit(1);
    }
    
    return h;
}

int Parent(Heap* h, int i){
    if(i <= 0 || i >= h -> count) return -1;

    return (i - 1) / 2;
}

int leftChild(Heap* h, int i){
    int left = 2 * i + 1;
    if (left >= h -> count) return -1;
    
    return left;
}

int rightChild(Heap* h, int i){
    int right = 2 * i + 2;
    if (right >= h-> count) return -1;
    
    return right;
}


void percolateDown(Heap* h, int i){
    int l, r, max, temp;
    l = leftChild(h, i);
    r = rightChild(h, i);
    
    if(l != -1 && h -> array[l] > h -> array[i]) max = l; // -1일경우, 해당 값이 없다는 뜻
    else max = i;
    
    if(r != -1 && h -> array[r] > h -> array[max]) max = r;
    
    if (max != i) {
        temp = h -> array[i];
        h -> array[i] = h -> array[max];
        h -> array[max] = temp;
        percolateDown(h, max);
    }
    
}

int deleteMax(Heap* h){
    
    int data;
    
    if(h -> count == 0) return -1;
    
    data = h -> array[0];
    h -> array [0] = h -> array[h -> count-1];
    h -> array [h -> count -1] = -1; //아무것도 저장 안된부분을 -1로 만듬
    h -> count--;
    percolateDown(h, 0);
    
    data = h -> array[0]; // return 할 최종 max값 갱신
    
    return data;
    
}

int getMax(Heap* h){
    return h -> array[0];
}

void resizeHeap(Heap* h){

    h -> capacity = h -> capacity + 1;
    
    h -> array = (int*)realloc(h -> array,sizeof(int) * h -> capacity);
    
}


void percolateUp(Heap* h, int i){
    
    int temp;
    
    while(i > 0 && h -> array[i] > h -> array[(i-1)/2]){ // 자식노드의 값이 부모노드 값보다 크다면, 자리 swap
        temp = h -> array[i/2];
        h -> array[i/2] = h -> array[i];
        h -> array[i] = temp;
        i /= 2;
        }
    
}

void insert(Heap* h, int data) {
    if (h -> count == h -> capacity) resizeHeap(h); // count가 capacity 값과 같다면 (배열을 모두 다썼다면) resizeHeap 실행
    
    h -> count++;
    int i = h -> count -1;
    h -> array[i] = data; //data 삽입 후
    percolateUp(h, i); // percolate up 실행

    
    if(h -> count < h -> capacity && h -> array[h -> count + 1] != -1){ // array 의 숫자가 삽입안된 count 뒤의 값들을 모두 -1 로 바꾸어줌
        for(int j = h -> count + 1 ; j < h -> capacity; j++){
            h -> array[j] = -1;
        };
    }
    
    }

void printHeap(Heap* h){
    for(int i =0; i < h->capacity; i++){
        printf("[%d] ", h->array[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    int i, n, item, max;
    Heap* heap = createHeap(5, 1);
    
    printf("\n========= 삽입 실행 =========\n", max);
    
    insert(heap, 10);
    insert(heap, 45);
    insert(heap, 19);
    
    printHeap(heap);
    
    insert(heap, 11);
    insert(heap, 96);
    insert(heap, 100);
    insert(heap, 18);
    
    printf("\n", max);
    
    printHeap(heap);
    
   
    max = getMax(heap);
    printf("\n maxnumber : %d\n", max);
    
    printf("\n========= 삭제 실행 =========\n", max);
    
    item = deleteMax(heap);
    printHeap(heap);
    printf("\n maxnumber : %d\n", item);
    
    item = deleteMax(heap);
    printHeap(heap);
    printf("\n maxnumber : %d\n", item);
    
    
    
    return 0;
}

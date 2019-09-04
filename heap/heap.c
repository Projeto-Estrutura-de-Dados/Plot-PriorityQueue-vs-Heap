#include <stdio.h>
#include <stdlib.h>

#ifndef swap
#define swap(x, y, T) { T aux = x; x = y; y = aux; }
#endif

#define MAX_HEAP_SIZE 999999

typedef struct heap {
    int size;
    int data[MAX_HEAP_SIZE];
} heap;

heap* createHeap() {
    heap *newHeap = (heap*) malloc(sizeof(heap));
    newHeap->size = 0;

    return newHeap;
}

int getParentIndex(int i) {
    return i >> 1;
}

int enqueueHeap(heap *heap, int item) {
    int cont = 1;
    heap->data[++heap->size] = item;

    int keyIndex = heap->size;
    int parentIndex = getParentIndex(heap->size);

    while (parentIndex >= 1 && heap->data[keyIndex] > heap->data[parentIndex]) {
        cont++;
        swap(heap->data[keyIndex], heap->data[parentIndex], int);
        keyIndex = parentIndex;
        parentIndex = getParentIndex(keyIndex);
    }

    return cont;
}

//int minHeapify(heap *heap, int i, int cont) {
//    int smallest = i;
//    int leftIndex = getLeftIndex(i);
//    int rightIndex = getRightIndex(i);
//
//    if(leftIndex <= heap->size && heap->data[leftIndex] <= heap->data[i]) {
//        cont++;
//        smallest = leftIndex;
//    }
//
//    if(rightIndex <= heap->size && heap->data[rightIndex] <= heap->data[smallest]) {
//        cont++;
//        smallest = rightIndex;
//    }
//
//    if(smallest != i) {
//        swap(heap->data[i], heap->data[smallest], int);
//
//        return minHeapify(heap, smallest, cont);
//    }
//    else{
//        return cont;
//    }
//
//}

void destroyHeap(heap *heap) {
    free(heap);
};
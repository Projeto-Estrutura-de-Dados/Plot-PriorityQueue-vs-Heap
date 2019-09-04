#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} node;

typedef struct priorityQueue {
    node *head;
} priorityQueue;

priorityQueue* createPriorityQueue() {
    priorityQueue *newPriorityQueue = (priorityQueue *) malloc(sizeof(priorityQueue));
    newPriorityQueue->head = NULL;

    return newPriorityQueue;
}

node* createNode(int item) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->item = item;
    newNode->next = NULL;

    return newNode;
}

priorityQueue* enqueuePq(priorityQueue *pq, int item, int *cont) {
    node *newNode = createNode(item);
    node *current = pq->head;
    node *previous = NULL;

    while(current && current->item < item) {
        *cont += 1;
        previous = current;
        current = current->next;
    }

    if(!previous) {
        newNode->next = current;
        pq->head = newNode;
    }
    else {
        previous->next = newNode;
        newNode->next = current;
    }

    return pq;
}

void destroyPriorityQueue(priorityQueue *pq) {
    node *current = pq->head;
    node *aux;

    while(current){
        aux = current;
        current = current->next;
        free(aux);
    }

    free(pq);
}
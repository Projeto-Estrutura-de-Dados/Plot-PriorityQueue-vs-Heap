#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./priorityQueue/priorityQueue.c"
#include "./heap/heap.c"

int main() {
    srand(time(NULL));

    FILE *heapFile = fopen("./heap/heapFile.txt", "w");

    if(!heapFile) {
        printf("Failed to open heapFile\n");
        return 0;
    }

    FILE *queueFile = fopen("./priorityQueue/queueFile.txt", "w");

    if(!queueFile) {
        printf("Failed to open queueFile\n");
        return 0;
    }

    heap *heap = createHeap();
    priorityQueue *queue = createPriorityQueue();

    int contHeap = 1, contQueue = 1, num, max;

    printf("Quantidade de numeros inseridos > ");
    scanf("%d", &max);

    fprintf(heapFile, "num, cont\n");
    fprintf(queueFile, "num, cont\n");

    for(int i = 0; i < max; ++i) {
        num = rand() % 10000;

        queue = enqueuePq(queue, num, &contQueue);
        contHeap = enqueueHeap(heap, num);

        fprintf(heapFile, "%d,%d\n", num, contHeap);
        fprintf(queueFile, "%d,%d\n", num, contQueue);

        contQueue = 1;
    }

    fclose(heapFile);
    fclose(queueFile);

    destroyHeap(heap);
    destroyPriorityQueue(queue);

    return 0;
}
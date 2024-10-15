#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct heap {
    int* array;
    int array_size;
    int heap_size;

} heap_t;

int left_node (int index) {
    //Perchè nella teoria l'array si numera a partire da 1
    if (index == 0){
        index += 1;
    }
    return index << 1;
}

int right_node (int index) {
    return (index << 1) | 1;
}

int parent_node (int index) {
    return index >> 1;
}

int swap(heap_t heap, int index_1, int index_2) {
    int temp_key = heap.array[index_1];
    
    printf("[SW] Before: index_1 %d, index_2 %d\n", heap.array[index_1], heap.array[index_2]);
    heap.array[index_1] = heap.array[index_2];
    heap.array[index_2] = temp_key;
    printf("[SW] After: index_1 %d, index_2 %d\n", heap.array[index_1], heap.array[index_2]);
    
    printf("\n");
    return 0;
}

//TO UPGRADE TO FIT BOTH MAX AND MIN HEAPIFY
int iteration = 0;
int heapify (heap_t heap, int index) {
    int left, right, parent, min;
    
    //DEBUG
    iteration += 1;
    printf("[H] Iteration n.%d\n", iteration);

    left = left_node(index);
    right = right_node(index);
    min = index;

    //Check LEFT(i)
    if (left < heap.heap_size && heap.array[left] < heap.array[min]) {
        min = left;
    }

    //Check RIGHT(i)
    if (right < heap.heap_size && heap.array[right] < heap.array[min]) {
        min = right;
    }

    //Check and reorder
    if (min != index){
        if (swap(heap, index, min) != 0){
            perror("Error while swapping items");
            exit(EXIT_FAILURE);
        }

        heapify(heap, min);
    }
    return 0;
}

int main (int argc, char* argv[]) {
    heap_t heap;

    printf("[MAIN] Program starts with 'argc' = %d\n", argc);

    if (argc < 3) {
        perror("Error! Not enough parameters");
        exit(EXIT_FAILURE);
    }

    if (atoi(argv[1]) != argc -2) {
        printf("Error! Size should be the same as number of inputed elements");
        exit(EXIT_FAILURE);
    }
    printf("[MAIN] Initializing heap...\n");
    heap.array_size = heap.heap_size = atoi(argv[1]);
    heap.array = (int*) malloc(sizeof(int) * heap.array_size);

    //Fill the array
    for (int i = 0; i < heap.array_size; i++) {
        heap.array[i] = atoi(argv[2+i]);
        printf("[MAIN] New item '%d' in array at index '%d'\n", heap.array[i], i);
    }
    printf("\n");

    printf("[MAIN] Heapifing array...\n");
    if (heapify(heap, 0) != 0) {
        perror("Error while doing heapify");
        exit(EXIT_FAILURE);
    }
    printf("\n");


    printf("[MAIN] Printing heapified array\n");
    for (int i = 0; i < heap.array_size; i++) {
        printf("[MAIN] Item '%d' in array at index '%d'\n", heap.array[i], i);
    }
    printf("\n");


    return 0; 
}
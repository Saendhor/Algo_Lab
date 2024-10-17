#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEAP_ROOT 1

typedef struct heap {
    int* array;
    int array_size;
    int heap_size;

} heap_t;

int left_node (int index) {
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
    printf("[H] Iteration n.%d with index %d\n", iteration, index);

    left = left_node(index);
    right = right_node(index);
    min = index;

    printf("[H] left: %d, right: %d, min: %d\n", left, right, min);
    printf("[H] item: %d, item: %d, val: %d\n", heap.array[left], heap.array[right], heap.array[min]);
    //Check LEFT(i)
    if (left < heap.heap_size && heap.array[left] < heap.array[min]) {
        min = left;
        printf("[H] left < heapsize && left (%d) < min (%d)\n", left, min);
    }

    //Check RIGHT(i)
    if (right < heap.heap_size && heap.array[right] < heap.array[min]) {
        min = right;
        printf("[H] right < heapsize && right (%d) < min (%d)\n", right, min);
    }

    //Check and reorder
    if (min != index){
        printf("[H] min (%d) != index (%d)\n", min, index);
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
    heap.array_size = heap.heap_size = atoi(argv[1]) + 1;
    printf("[MAIN] Array_size: %d\n", heap.array_size);
    heap.array = (int*) malloc(sizeof(int) * heap.array_size);

    //Fill the array
    for (int i = 1; i < heap.array_size; i++) {
        heap.array[i] = atoi(argv[2+i-1]);
        printf("[MAIN] New item '%d' in array at index '%d'\n", heap.array[i], i);
    }
    printf("\n");

    printf("[MAIN] Heapifing array. Heap-size: %d\n", heap.heap_size);
    if (heapify(heap, HEAP_ROOT) != 0) {
        perror("Error while doing heapify");
        exit(EXIT_FAILURE);
    }
    printf("\n");


    printf("[MAIN] Printing heapified array\n");
    for (int i = 1; i < heap.array_size; i++) {
        printf("[MAIN] Item '%d' in array at index '%d'\n", heap.array[i], i);
    }
    printf("\n");


    return 0; 
}
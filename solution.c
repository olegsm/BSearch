#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct array {
    uint64_t size;
    int32_t* data;
} array_t;

void dump(array_t* array)
{
    for (int i = 0; i < array->size; ++i) {
        printf("[%d] %d, ", i, array->data[i]);
    }
    printf("\n");
}

uint64_t binary_search(array_t* array, int32_t k)
{
    if (!array || !array->data || array->size == 0 || array->data[array->size - 1] < k)
        return -1;

    if (array->data[0] > k)
        return 0;

    uint64_t start = 0;
    uint64_t end = array->size - 1;
    while (start != end) {
        uint64_t pivot = start + (end - start) / 2;
        if (array->data[pivot] <= k)
            start = pivot + 1;
        else
            end = pivot;
    }
    return start;
}

int32_t main(int32_t argn, char** argv)
{
    int32_t data[] = { 0,0,1,2,2,2,3,3,3,3,3,3,3,3,39,73,74,75,79,100,1000,1000000,3000000 };

    array_t array;
    array.size = sizeof(data) / sizeof(data[0]);
    array.data = &data[0];

    for (int i = 0; i < array.size; ++i) {
        int32_t k = array.data[i] + 1;
        uint64_t index = binary_search(&array, k);
        printf("k=%d, found=%ld\n", k, index);
    }
    return 0;
}


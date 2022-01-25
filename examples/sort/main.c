#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/vector.h"
#include "../../src/priority_queue.h"

/*
This implementation of heapsort is very easy and work well.
But it requires 2 arrays : the initial array to sort and the temp priority queue array.
It's possible to have a more efficient (in memory) implementation with only the initial array :
    https://en.wikipedia.org/wiki/Heapsort
*/
void heap_sort(int a[], size_t size)
{
    int_priority_queue pq = int_priority_queue_create();

    for (unsigned int i = 0 ; i < size ; i++)
        int_priority_queue_push(pq, a[i]);

    for (unsigned int i = 0 ; i < size ; i++)
        a[i] = int_priority_queue_pop(pq);

    int_priority_queue_destroy(pq);
}

int main()
{
    int a[] = { 0, 25, 32, 10, 1, 50, 20, 100, -1, 27, 28, 10, 3, 99, -10, -1, 110, 55, 75, -2, 0 };
    size_t size = sizeof(a) / sizeof(int);

    heap_sort(a,size);

    for (unsigned int i = 0 ; i < size ; i++)
        printf("%i:%i\n", i, a[i]);

    return EXIT_SUCCESS;
}

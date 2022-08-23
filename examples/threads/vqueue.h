/*

*/
#ifndef VQUEUE_H
#define VQUEUE_H

#define VQUEUE_CAPACITY 50

#include "../../src/linked_list.h"
#include "../../src/queue.h"

typedef struct _vegetables_queue {
    size_t size;
    queue vqueue;
} *vegetables_queue;

vegetables_queue vqueue_create();
void vqueue_destroy(vegetables_queue);
void vqueue_push(vegetables_queue, const char*);
char* vqueue_pop(vegetables_queue);

#endif

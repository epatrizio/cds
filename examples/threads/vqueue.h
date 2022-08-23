/*

*/
#ifndef VQUEUE_H
#define VQUEUE_H

#define VQUEUE_CAPACITY 100
#define VPRODUCER_PRODUCTION 50

#include "../../src/linked_list.h"
#include "../../src/queue.h"

typedef struct _vegetables_queue {
    size_t size;
    queue vqueue;
} *vegetables_queue;

typedef struct _vegetables_producer {
    const char *vname;
    unsigned short int current_production;
} *vegetables_producer;

vegetables_queue vqueue_create();
void vqueue_destroy(vegetables_queue);
void vqueue_push(vegetables_queue, const char*);
char* vqueue_pop(vegetables_queue);

vegetables_producer vproducer_create(const char*);
void vproducer_destroy(vegetables_producer);

#endif

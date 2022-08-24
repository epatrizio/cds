#ifndef VQUEUE_H
#define VQUEUE_H

#define VQUEUE_CAPACITY 4
#define VPRODUCER_PRODUCTION 10
#define VCONSUMER_NEED 5

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

typedef struct _vegetables_consumer {
    const char *cname;
    unsigned short int current_consumption;
} *vegetables_consumer;

void mutex_init();
void mutex_destroy();

vegetables_queue vqueue_create();
void vqueue_destroy(vegetables_queue);
void vqueue_push(vegetables_queue, const char*);
char* vqueue_pop(vegetables_queue);

vegetables_producer vproducer_create(const char*);
void vproducer_destroy(vegetables_producer);
void vproducer_push_vegetables(vegetables_producer, vegetables_queue);

vegetables_consumer vconsumer_create(const char*);
void vconsumer_destroy(vegetables_consumer);
void vconsumer_pop_vegetables(vegetables_consumer, vegetables_queue);

#endif

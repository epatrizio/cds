#include <stdbool.h>
#include <stdlib.h>

#include "vqueue.h"

vegetables_queue vqueue_create()
{
    vegetables_queue vq = malloc(sizeof(vegetables_queue));
    vq->size = 0;
    vq->vqueue = queue_create();
    return vq;
}

void vqueue_destroy(vegetables_queue vq)
{
    queue_destroy(vq->vqueue);
    free(vq);
}

void vqueue_push(vegetables_queue vq, const char* vegetable_name)
{
    if (vq->size < VQUEUE_CAPACITY) {
        vq->size++;
        return queue_push(vq->vqueue, vegetable_name);
    }    
}

char* vqueue_pop(vegetables_queue vq)
{
    if (vq->size > 0) {
        vq->size--;
        return queue_pop(vq->vqueue);
    }
    else
        return NULL;
}

vegetables_producer vproducer_create(const char* vname)
{
    vegetables_producer vp = malloc(sizeof(vegetables_producer));
    vp->vname = vname;
    vp->current_production = 0;
    return vp;
}

void vproducer_destroy(vegetables_producer vp)
{
    free(vp);
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#include "vqueue.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void mutex_init()
{
    pthread_mutex_init(&mutex, NULL);
}

void mutex_destroy()
{
    pthread_mutex_destroy(&mutex);
}

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
    pthread_mutex_lock(&mutex);

    vq->size++;
    queue_push(vq->vqueue, vegetable_name);
    if (vq->size < VQUEUE_CAPACITY)
        pthread_cond_signal(&cond);
    else
        pthread_cond_wait(&cond, &mutex);

    pthread_mutex_unlock(&mutex);
}

char* vqueue_pop(vegetables_queue vq)
{
    pthread_mutex_lock(&mutex);

    vq->size--;
    char *veg = queue_pop(vq->vqueue);
    if (vq->size > 0)
        pthread_cond_signal(&cond);
    else
        pthread_cond_wait(&cond, &mutex);

    pthread_mutex_unlock(&mutex);

    return veg;
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

void vproducer_push_vegetables(vegetables_producer vp, vegetables_queue vq)
{
    char tmp_vname[20];
    char tmp_prod[5];

    while (vp->current_production < VPRODUCER_PRODUCTION) {
        vp->current_production++;
        sprintf(tmp_prod, "%d", vp->current_production);
        strcpy(tmp_vname, vp->vname);
        strcat(tmp_vname, tmp_prod);
        vqueue_push(vq, tmp_vname);
    }
}

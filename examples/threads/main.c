#include <stdbool.h>
#include <stdlib.h>

#include <pthread.h>

#include "vqueue.h"

vegetables_queue vq;

void *vprod_push_veg(void *arg)
{
    vproducer_push_vegetables(arg, vq);
    return NULL;
}

int main()
{
    pthread_t th_1, th_2, th_3;
    void *status;

    vq = vqueue_create();

    vegetables_producer vp_1 = vproducer_create("apple");
    vegetables_producer vp_2 = vproducer_create("pear");
    vegetables_producer vp_3 = vproducer_create("banana");

    mutex_init();

    pthread_create(&th_1, NULL, vprod_push_veg, vp_1);
    pthread_create(&th_2, NULL, vprod_push_veg, vp_2);
    pthread_create(&th_3, NULL, vprod_push_veg, vp_3);

    pthread_join(th_1, &status);
    pthread_join(th_2, &status);
    pthread_join(th_3, &status);

    mutex_destroy();

    vproducer_destroy(vp_1);
    vproducer_destroy(vp_2);
    vproducer_destroy(vp_3);

    vqueue_destroy(vq);

    return EXIT_SUCCESS;
}

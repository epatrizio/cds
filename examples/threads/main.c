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

void *vcons_pop_veg(void *arg)
{
    vconsumer_pop_vegetables(arg, vq);
    return NULL;
}

int main()
{
    pthread_t th_1, th_2, th_3;
    pthread_t th_4, th_5;
    void *status;

    vq = vqueue_create();

    vegetables_producer vp_1 = vproducer_create("apple");
    vegetables_producer vp_2 = vproducer_create("pear");
    vegetables_producer vp_3 = vproducer_create("banana");

    vegetables_consumer vc_1 = vconsumer_create("C1");
    vegetables_consumer vc_2 = vconsumer_create("C2");

    mutex_init();

    pthread_create(&th_1, NULL, vprod_push_veg, vp_1);
    pthread_create(&th_2, NULL, vprod_push_veg, vp_2);
    pthread_create(&th_3, NULL, vprod_push_veg, vp_3);

    pthread_create(&th_4, NULL, vcons_pop_veg, vc_1);
    pthread_create(&th_5, NULL, vcons_pop_veg, vc_2);

    // we only wait the end of consumers threads (We consider that the production is higher than the needs)
    pthread_join(th_4, &status);
    pthread_join(th_5, &status);

    mutex_destroy();

    vproducer_destroy(vp_1);
    vproducer_destroy(vp_2);
    vproducer_destroy(vp_3);

    vqueue_destroy(vq);

    return EXIT_SUCCESS;
}

#include <stdbool.h>
#include <stdlib.h>

#include "vqueue.h"

int main()
{
    vegetables_queue vq = vqueue_create();

    vegetables_producer vp_1 = vproducer_create("apple");
    vegetables_producer vp_2 = vproducer_create("pear");
    vegetables_producer vp_3 = vproducer_create("banana");


    vproducer_destroy(vp_1);
    vproducer_destroy(vp_2);
    vproducer_destroy(vp_3);

    vqueue_destroy(vq);

    return EXIT_SUCCESS;
}

#include <stdbool.h>
#include <stdlib.h>

#include "vqueue.h"

int main()
{
    vegetables_queue vq = vqueue_create();
    vqueue_destroy(vq);

    return EXIT_SUCCESS;
}

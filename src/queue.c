#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "queue.h"

queue* queue_create()
{
    return linked_list_create();
}

void queue_destroy(queue *q)
{
    linked_list_destroy(q);
}

bool queue_is_empty(queue *q)
{
    return linked_list_is_empty(q);
}

void queue_push(queue *q, const char *string)
{
    linked_list_add_first(q, string);
}

char* queue_pop(queue *q)
{
    return linked_list_remove_last(q);
}
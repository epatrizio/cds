#ifndef QUEUE_H
#define QUEUE_H

typedef linked_list_elt queue_elt;

typedef linked_list queue;

queue* queue_create();
void queue_destroy(queue*);
bool queue_is_empty(queue*);
void queue_push(queue*, const char*);
char* queue_pop(queue*);

#endif

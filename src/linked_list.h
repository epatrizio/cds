#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _linked_list_elt {
    char *string;
    struct _linked_list_elt *next;
    struct _linked_list_elt *previous;
} linked_list_elt;

typedef struct _linked_list {
    linked_list_elt *first;
    linked_list_elt *last;
    size_t size;
} *linked_list;

linked_list linked_list_create();
void linked_list_destroy(linked_list);
bool linked_list_is_empty(linked_list);
void linked_list_add_first(linked_list, const char*);
char* linked_list_remove_first(linked_list);
void linked_list_add_last(linked_list, const char*);
char* linked_list_remove_last(linked_list);

#endif

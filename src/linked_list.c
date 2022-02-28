#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

linked_list linked_list_create()
{
    linked_list empty_ll = malloc(sizeof(struct _linked_list));
    empty_ll->first = NULL;
    empty_ll->last = NULL;
    empty_ll->size = 0;

    return empty_ll;
}

void linked_list_destroy(linked_list ll)
{
    linked_list_elt *current_elt = ll->first;
    while (current_elt != NULL) {
        linked_list_elt *next_elt = current_elt->next;
        free(current_elt->string);
        free(current_elt);
        current_elt = next_elt;
    }
    free(ll);
}

bool linked_list_is_empty(linked_list ll)
{
    return (ll->size == 0);
}

void linked_list_add_first(linked_list ll, const char *string)
{
    char *w = malloc(strlen(string)+1);
    strcpy(w, string);

    linked_list_elt *elt = malloc(sizeof(linked_list_elt));
    elt->string = w;
    elt->next = ll->first;
    elt->previous = NULL;

    if (ll->first != NULL) ll->first->previous = elt;

    ll->first = elt;

    if (ll->last == NULL) ll->last = elt;

    ll->size++;
}

char* linked_list_remove_first(linked_list ll)
{
    if (linked_list_is_empty(ll)) return NULL;

    linked_list_elt *first_elt = ll->first;

    char *w = malloc(strlen(first_elt->string)+1);
    strcpy(w, first_elt->string);

    if (ll->size == 1) {
        ll->first = NULL;
        ll->last = NULL;
    } else {
        ll->first = first_elt->next;
        ll->first->previous = NULL;
    }

    free(first_elt->string);
    free(first_elt);

    ll->size--;

    return w;
}

void linked_list_add_last(linked_list ll, const char *string)
{
    char *w = malloc(strlen(string)+1);
    strcpy(w, string);

    linked_list_elt *elt = malloc(sizeof(linked_list_elt));
    elt->string = w;
    elt->next = NULL;
    elt->previous = ll->last;

    if (ll->last != NULL) ll->last->next = elt;

    ll->last = elt;

    if (ll->first == NULL) ll->first = elt;

    ll->size++;
}

char* linked_list_remove_last(linked_list ll)
{
    if (linked_list_is_empty(ll)) return NULL;

    linked_list_elt *last_elt = ll->last;

    char *w = malloc(strlen(last_elt->string)+1);
    strcpy(w, last_elt->string);

    if (ll->size == 1) {
        ll->first = NULL;
        ll->last = NULL;
    } else {
        ll->last = last_elt->previous;
        ll->last->next = NULL;
    }

    free(last_elt->string);
    free(last_elt);

    ll->size--;

    return w;
}

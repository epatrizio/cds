#include <stdio.h>
#include <stdlib.h>

#include "tests_linked_list.h"

void test_ll_empty(const void *function_node)
{
    linked_list *ll = linked_list_create();

    assert_true(linked_list_is_empty(ll), function_node);

    linked_list_destroy(ll);
}

void test_ll(const void *function_node)
{
    linked_list *ll = linked_list_create();

    linked_list_add_first(ll, "insert 1 first");
    linked_list_add_first(ll, "insert 2 first");
    linked_list_add_last(ll, "insert 3 last");

    assert_false(linked_list_is_empty(ll), function_node);

    assert_equals_int(3, ll->size, function_node);
    assert_equals_charp("insert 2 first", ll->first->string, function_node);
    assert_equals_charp("insert 3 last", ll->last->string, function_node);

    assert_equals_charp("insert 3 last", linked_list_remove_last(ll), function_node);
    assert_equals_charp("insert 2 first", linked_list_remove_first(ll), function_node);

    assert_equals_int(1, ll->size, function_node);

    assert_equals_charp("insert 1 first", ll->first->string, function_node);
    assert_equals_charp("insert 1 first", ll->last->string, function_node);

    assert_equals_charp("insert 1 first", linked_list_remove_first(ll), function_node);
    assert_true(linked_list_is_empty(ll), function_node);

    linked_list_destroy(ll);
}

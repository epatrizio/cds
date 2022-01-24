#include <stdio.h>
#include <stdlib.h>

#include "tests_priority_queue.h"

void test_char_pq_empty(const void *function_node)
{
    char_priority_queue pq = char_priority_queue_create();

    assert_true(char_priority_queue_is_empty(pq), function_node);

    char_priority_queue_destroy(pq);
}

void test_int_pq(const void *function_node)
{
    int_priority_queue pq = int_priority_queue_create();

    int_priority_queue_push(pq, 10);
    int_priority_queue_push(pq, 100);
    int_priority_queue_push(pq, 5);
    int_priority_queue_push(pq, 3);
    int_priority_queue_push(pq, 50);
    int_priority_queue_push(pq, 1);
    int_priority_queue_push(pq, 30);
    int_priority_queue_push(pq, 2);
    int_priority_queue_push(pq, 99);
    int_priority_queue_push(pq, 4);
    int_priority_queue_push(pq, 45);
    int_priority_queue_push(pq, 110);

    assert_false(int_priority_queue_is_empty(pq), function_node);

    assert_equals_int(1, int_priority_queue_pop(pq),function_node);
    assert_equals_int(2, int_priority_queue_pop(pq),function_node);
    assert_equals_int(3, int_priority_queue_pop(pq),function_node);
    assert_equals_int(4, int_priority_queue_pop(pq),function_node);
    assert_equals_int(5, int_priority_queue_pop(pq),function_node);
    assert_equals_int(10, int_priority_queue_pop(pq),function_node);
    assert_equals_int(30, int_priority_queue_pop(pq),function_node);
    assert_equals_int(45, int_priority_queue_pop(pq),function_node);
    assert_equals_int(50, int_priority_queue_pop(pq),function_node);
    assert_equals_int(99, int_priority_queue_pop(pq),function_node);
    assert_equals_int(100, int_priority_queue_pop(pq),function_node);
    assert_equals_int(110, int_priority_queue_pop(pq),function_node);

    assert_true(int_priority_queue_is_empty(pq), function_node);

    int_priority_queue_destroy(pq);
}
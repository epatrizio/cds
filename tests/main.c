#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests_vector.h"
#include "tests_stack.h"
#include "tests_priority_queue.h"
#include "tests_linked_list.h"
#include "tests_queue.h"
#include "tests_hash_set.h"
#include "tests_hash_map.h"
#include "tests_graph.h"

int main(int argc, char *argv[])
{
    TestSuite *ts_vector = createTestSuite("VECTOR");
    addTestFunction(ts_vector, "char_vector_empty", test_char_vector_empty);
    addTestFunction(ts_vector, "double_vector_resize", test_double_vector_resize);
    addTestFunction(ts_vector, "int_vector", test_int_vector);
    runTestSuite(ts_vector, argc, argv);
    displayTestSuite(ts_vector);
    deleteTestSuite(ts_vector);

    TestSuite *ts_cs_vector = createTestSuite("CUSTOM_STRUCT_VECTOR");
    addTestFunction(ts_cs_vector, "custom_struct_vector", test_custom_struct_vector);
    runTestSuite(ts_cs_vector, argc, argv);
    displayTestSuite(ts_cs_vector);
    deleteTestSuite(ts_cs_vector);

    TestSuite *ts_stack = createTestSuite("STACK");
    addTestFunction(ts_stack, "char_stack_empty", test_char_stack_empty);
    addTestFunction(ts_stack, "float_stack", test_float_stack);
    runTestSuite(ts_stack, argc, argv);
    displayTestSuite(ts_stack);
    deleteTestSuite(ts_stack);

    TestSuite *ts_pq = createTestSuite("PRIORITY_QUEUE");
    addTestFunction(ts_pq, "char_pq_empty", test_char_pq_empty);
    addTestFunction(ts_pq, "int_pq", test_int_pq);
    addTestFunction(ts_pq, "char_pq", test_char_pq);
    runTestSuite(ts_pq, argc, argv);
    displayTestSuite(ts_pq);
    deleteTestSuite(ts_pq);

    TestSuite *ts_ll = createTestSuite("LINKED_LIST");
    addTestFunction(ts_ll, "ll_empty", test_ll_empty);
    addTestFunction(ts_ll, "ll", test_ll);
    runTestSuite(ts_ll, argc, argv);
    displayTestSuite(ts_ll);
    deleteTestSuite(ts_ll);

    TestSuite *ts_queue = createTestSuite("QUEUE");
    addTestFunction(ts_queue, "queue_empty", test_queue_empty);
    addTestFunction(ts_queue, "queue", test_queue);
    runTestSuite(ts_queue, argc, argv);
    displayTestSuite(ts_queue);
    deleteTestSuite(ts_queue);

    TestSuite *ts_hs = createTestSuite("HASH_SET");
    addTestFunction(ts_hs, "hash_set", test_hash_set);
    runTestSuite(ts_hs, argc, argv);
    displayTestSuite(ts_hs);
    deleteTestSuite(ts_hs);

    TestSuite *ts_hm = createTestSuite("HASH_MAP");
    addTestFunction(ts_hm, "hash_map", test_hash_map);
    runTestSuite(ts_hm, argc, argv);
    displayTestSuite(ts_hm);
    deleteTestSuite(ts_hm);

    TestSuite *ts_g = createTestSuite("GRAPH");
    addTestFunction(ts_g, "graph", test_graph);
    addTestFunction(ts_g, "graph_dfs", test_graph_dfs);
    addTestFunction(ts_g, "graph_bfs", test_graph_bfs);
    runTestSuite(ts_g, argc, argv);
    displayTestSuite(ts_g);
    deleteTestSuite(ts_g);

    return EXIT_SUCCESS;
}
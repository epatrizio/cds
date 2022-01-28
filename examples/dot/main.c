#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/vector.h"
#include "../../src/linked_list.h"
#include "../../src/queue.h"
#include "../../src/hash_utils.h"
#include "../../src/hash_set.h"
#include "../../src/graph.h"

size_t intl_hash_code(const char *str)
{
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
    graph g = graph_create(0);

    g = graph_add_vertex(g, "A", (size_t (*)(const char*))(intl_hash_code));
    g = graph_add_vertex(g, "B", (size_t (*)(const char*))(intl_hash_code));
    g = graph_add_vertex(g, "C", (size_t (*)(const char*))(intl_hash_code));
    g = graph_add_vertex(g, "D", (size_t (*)(const char*))(intl_hash_code));
    g = graph_add_vertex(g, "E", (size_t (*)(const char*))(intl_hash_code));
    g = graph_add_vertex(g, "F", (size_t (*)(const char*))(intl_hash_code));

    graph_add_edge(g, "A", "B", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "B", "C", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "C", "D", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "E", "F", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "A", "D", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "D", "B", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "C", "F", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "F", "C", (size_t (*)(const char*))(intl_hash_code));
    graph_add_edge(g, "D", "E", (size_t (*)(const char*))(intl_hash_code));

    graph_dot(g);

    graph_destroy(g);

    return EXIT_SUCCESS;
}

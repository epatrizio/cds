#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "hash_utils.h"
#include "hash_set.h"
#include "graph.h"

// TODO : tests
graph resize_graph(graph g, size_t (*hash_fct)(const char *str))
{
    graph new_g = graph_create(graph_bucket_vector_size(g)*2);

    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            new_g = graph_add_vertex(new_g, elt.vertex, *hash_fct);
            // TODO elt.successors reconstruct/or get
        }
    }

    graph_destroy(g);

    return new_g;
}

graph graph_create(size_t initial_size)
{
    graph g = graph_bucket_vector_create();

    graph_bucket_vector_resize(g, (initial_size>0) ? initial_size : GRAPH_INITIAL_SIZE);

    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++)
        graph_bucket_vector_set(g, i, graph_elt_vector_create());

    return g;
}

void graph_destroy(graph g)
{
    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            free(elt.vertex);
            hash_set_destroy(elt.successors); // check ...
            //free(elt.successors);
        }
        graph_elt_vector_destroy(b);
    }

    graph_bucket_vector_destroy(g);
}

graph graph_add_vertex(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    graph_bucket b = graph_bucket_vector_get(g, hash_code_modulo(vertex, graph_bucket_vector_size(g), *hash_fct));

    char *cp_vertex = malloc(strlen(vertex)+1);
    strcpy(cp_vertex, vertex);

    graph_elt e = {cp_vertex, hash_set_create(0)};

    for (unsigned int i=0 ; i<graph_elt_vector_size(b) ; i++) {
        graph_elt elt = graph_elt_vector_get(b, i);
        if (strcmp(vertex, elt.vertex) == 0) {  // check hash_table (fix?)
            free(elt.vertex);
            hash_set_destroy(elt.successors);
            graph_elt_vector_remove(b, i);
            break;   // check, before continue;
        }
    }

    graph_elt_vector_add(b, graph_elt_vector_size(b), e);

    if (graph_elt_vector_size(b) > GRAPH_BUCKET_MAX_SIZE)
        g = resize_graph(g, *hash_fct);

    return g;
}

void graph_add_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    // 0. check: vertex_t must be a vertex!
    graph_bucket b_t = graph_bucket_vector_get(g, hash_code_modulo(vertex_t, graph_bucket_vector_size(g), *hash_fct));
    bool t_is_a_vertex = false;
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_t) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_t, i);
        if (strcmp(vertex_t, elt.vertex) == 0) {
            t_is_a_vertex = true;
            break;
        }
    }
    if (!t_is_a_vertex) return;

    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            char *cp_vertex_t = malloc(strlen(vertex_t)+1);
            strcpy(cp_vertex_t, vertex_t);
            elt.successors = hash_set_add(elt.successors, cp_vertex_t, *hash_fct);
            break;
        }
    }
}

bool graph_has_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            return hash_set_contains(elt.successors, vertex_t, *hash_fct);
        }
    }
    return false;
}

bool graph_remove_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            return hash_set_remove(elt.successors, vertex_t, *hash_fct);
        }
    }
    return false;
}

// in progress > tests ... +: remove in edges
bool graph_remove_vertex(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    graph_bucket b = graph_bucket_vector_get(g, hash_code_modulo(vertex, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b) ; i++) {
        graph_elt elt = graph_elt_vector_get(b, i);
        if (strcmp(vertex, elt.vertex) == 0) {
            //free(elt.vertex);
            //hash_set_destroy(elt.successors);
            graph_bucket_vector_set(g, i, graph_elt_vector_create());
            return true;
        }
    }
    return false;
}

vector_init_fct(graph_elt)
vector_init_fct(graph_bucket)

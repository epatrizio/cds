#include <assert.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "hash_set.h"

unsigned long hash_code_modulo(const char *string, size_t modulo, size_t (*hash_fct)(const char *str))
{
    if (modulo == 0) return 0;

    return (*hash_fct)(string) % modulo;
}

hash_set hash_set_create(size_t initial_size)
{
    hash_set hs = hs_elts_vector_create();

    hs_elts_vector_resize(hs, (initial_size>0) ? initial_size : INITIAL_SIZE);

    for (unsigned int i=0 ; i<hs_elts_vector_size(hs) ; i++)
        hs_elts_vector_set(hs, i, hs_elt_vector_create());

    return hs;
}

void hash_set_destroy(hash_set hs)
{
    for (unsigned int i=0 ; i<hs_elts_vector_size(hs) ; i++)
        hs_elt_vector_destroy(hs_elts_vector_get(hs, i));

    hs_elts_vector_destroy(hs);
}

bool hash_set_contains(hash_set hs, const char *string, size_t (*hash_fct)(const char *str))
{
    hs_elts he = hs_elts_vector_get(hs, hash_code_modulo(string, hs_elts_vector_size(hs), *hash_fct));

    for (unsigned int i=0 ; i<hs_elt_vector_size(he) ; i++) {
        hs_elt elt = hs_elt_vector_get(he, i);
        if (strcmp(string, elt.string) == 0)
            return true;
    }
    return false;
}

void hash_set_add(hash_set hs, const char *string, size_t (*hash_fct)(const char *str))
{
    if (hash_set_contains(hs, string, *hash_fct)) return;

    hs_elts he = hs_elts_vector_get(hs, hash_code_modulo(string, hs_elts_vector_size(hs), *hash_fct));

    char *str = malloc(strlen(string)+1);
    strcpy(str, string);

    hs_elt e = {str};
    hs_elt_vector_add(he, hs_elt_vector_size(he), e);
}

bool hash_set_remove(hash_set hs, const char *string, size_t (*hash_fct)(const char *str))
{
    hs_elts he = hs_elts_vector_get(hs, hash_code_modulo(string, hs_elts_vector_size(hs), *hash_fct));
    for (unsigned int i=0 ; i<hs_elt_vector_size(he) ; i++) {
        hs_elt elt = hs_elt_vector_get(he, i);
        if (strcmp(string, elt.string) == 0) {
            hs_elt_vector_remove(he, i);
            return true;
        }
    }
    return false;
}

vector_init_fct(hs_elt)
vector_init_fct(hs_elts)

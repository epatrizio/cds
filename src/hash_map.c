#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "hash_utils.h"
#include "hash_map.h"

hash_map resize_hash_map(hash_map hm, size_t (*hash_fct)(const char *str))
{
    hash_map new_hm = hash_map_create(hm_bucket_vector_size(hm)*2);

    for (unsigned int i=0 ; i<hm_bucket_vector_size(hm) ; i++) {
        hm_bucket b = hm_bucket_vector_get(hm, i);
        for (unsigned int j=0 ; j<hm_elt_vector_size(b) ; j++) {
            hm_elt elt = hm_elt_vector_get(b, j);
            new_hm = hash_map_add(new_hm, elt.key, elt.value, *hash_fct);
        }
    }

    hash_map_destroy(hm);

    return new_hm;
}

hash_map hash_map_create(size_t initial_size)
{
    hash_map hm = hm_bucket_vector_create();

    hm_bucket_vector_resize(hm, (initial_size>0) ? initial_size : HASH_MAP_INITIAL_SIZE);

    for (unsigned int i=0 ; i<hm_bucket_vector_size(hm) ; i++)
        hm_bucket_vector_set(hm, i, hm_elt_vector_create());

    return hm;
}

void hash_map_destroy(hash_map hm)
{
    for (unsigned int i=0 ; i<hm_bucket_vector_size(hm) ; i++) {
        hm_bucket b = hm_bucket_vector_get(hm, i);
        for (unsigned int j=0 ; j<hm_elt_vector_size(b) ; j++) {
            hm_elt elt = hm_elt_vector_get(b, j);
            free(elt.key);
            free(elt.value);
        }
        hm_elt_vector_destroy(b);
    }

    hm_bucket_vector_destroy(hm);
}

bool hash_map_contains(hash_map hm, const char *key, size_t (*hash_fct)(const char *str))
{
    hm_bucket b = hm_bucket_vector_get(hm, hash_code_modulo(key, hm_bucket_vector_size(hm), *hash_fct));

    for (unsigned int i=0 ; i<hm_elt_vector_size(b) ; i++) {
        hm_elt elt = hm_elt_vector_get(b, i);
        if (strcmp(key, elt.key) == 0)
            return true;
    }
    return false;
}

char* hash_map_get(hash_map hm, const char *key, size_t (*hash_fct)(const char *str))
{
    hm_bucket b = hm_bucket_vector_get(hm, hash_code_modulo(key, hm_bucket_vector_size(hm), *hash_fct));

    for (unsigned int i=0 ; i<hm_elt_vector_size(b) ; i++) {
        hm_elt elt = hm_elt_vector_get(b, i);
        if (strcmp(key, elt.key) == 0)
            return elt.value;
    }
    return NULL;
}

hash_map hash_map_add(hash_map hm, const char *key, const char *value, size_t (*hash_fct)(const char *str))
{
    hm_bucket b = hm_bucket_vector_get(hm, hash_code_modulo(key, hm_bucket_vector_size(hm), *hash_fct));

    char *cp_key = malloc(strlen(key)+1);
    strcpy(cp_key, key);

    char *cp_value = malloc(strlen(value)+1);
    strcpy(cp_value, value);

    hm_elt e = {cp_key, cp_value};

    for (unsigned int i=0 ; i<hm_elt_vector_size(b) ; i++) {
        hm_elt elt = hm_elt_vector_get(b, i);
        if (strcmp(key, elt.key) == 0) {
            hm_elt_vector_remove(b, i);
            continue;
        }
    }

    hm_elt_vector_add(b, hm_elt_vector_size(b), e);

    if (hm_elt_vector_size(b) > HASH_MAP_BUCKET_MAX_SIZE)
        hm = resize_hash_map(hm, *hash_fct);

    return hm;
}

bool hash_map_remove(hash_map hm, const char *key, size_t (*hash_fct)(const char *str))
{
    hm_bucket b = hm_bucket_vector_get(hm, hash_code_modulo(key, hm_bucket_vector_size(hm), *hash_fct));
    for (unsigned int i=0 ; i<hm_elt_vector_size(b) ; i++) {
        hm_elt elt = hm_elt_vector_get(b, i);
        if (strcmp(key, elt.key) == 0) {
            hm_elt_vector_remove(b, i);
            return true;
        }
    }
    return false;
}

vector_init_fct(hm_elt)
vector_init_fct(hm_bucket)

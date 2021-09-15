#ifndef HASH_SET_H
#define HASH_SET_H

#define INITIAL_SIZE 10

typedef struct _hs_elt {
   char *string;
} hs_elt;

vector_init(hs_elt)  // Will contain elts with same hash_code

typedef hs_elt_vector hs_elts;

vector_init(hs_elts)  // The HashSet based on a vector (A vector of elts vectors)

typedef hs_elts_vector hash_set;

hash_set hash_set_create(size_t);
void hash_set_destroy(hash_set);
bool hash_set_contains(hash_set, const char*, size_t (*hash_fct)(const char*));  // hash function is a pointer function
void hash_set_add(hash_set, const char*, size_t (*hash_fct)(const char*));
bool hash_set_remove(hash_set, const char*, size_t (*hash_fct)(const char*));

#endif

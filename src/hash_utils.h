#ifndef HASH_UTILS_H
#define HASH_UTILS_H

size_t hash_code_modulo(const char*, size_t, size_t (*hash_fct)(const char*));

#endif

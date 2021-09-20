#include <stdlib.h>

#include "hash_utils.h"

size_t hash_code_modulo(const char *string, size_t modulo, size_t (*hash_fct)(const char *str))
{
    if (modulo == 0) return 0;

    return (*hash_fct)(string) % modulo;
}

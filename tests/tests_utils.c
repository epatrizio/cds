#include <stdlib.h>

#include "tests_utils.h"

// programmer defines his own hash function (same signature)
// Here is an example http://www.cse.yorku.ca/~oz/hash.html
size_t hash_code(const char *str)
{
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

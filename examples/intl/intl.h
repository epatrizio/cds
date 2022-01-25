/*
This micro library is a simple (quick and dirty!) example of hash_map use.
The HashMap data structure is used for a little/naive i18n component.
*/
#ifndef INTL_H
#define INTL_H

#define DEFAULT_LOCALE "en"

#include "../../src/vector.h"
#include "../../src/hash_utils.h"
#include "../../src/hash_map.h"

typedef hash_map intl_component;

void intl_set_locale(const char*);
char* intl_get_current_locale();
intl_component intl_create();
void intl_destroy(intl_component);
char* intl_translate(intl_component, const char*, const char*);
char* intl_current_translate(intl_component, const char*);
intl_component intl_add_translation(intl_component, const char*, const char*, const char*);
intl_component intl_load_locale_file(intl_component, const char*, const char*);

#endif

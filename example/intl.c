#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intl.h"

char *current_locale = DEFAULT_LOCALE;

size_t intl_hash_code(const char *str)
{
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

char* generate_locale_key(const char *key, const char *locale)
{
    char *locale_key = malloc(strlen(key)+strlen(locale)+2);
    strcpy(locale_key, key);
    strcat(locale_key, "-");
    strcat(locale_key, locale);

    return locale_key;
}

char* intl_get_current_locale()
{
    return current_locale;    
}

void intl_set_locale(const char *locale)
{
    char *new_locale = malloc(strlen(locale)+1);
    strcpy(new_locale, locale);

    current_locale = new_locale;
}

intl_component intl_create()
{
    return hash_map_create(0);
}

void intl_destroy(intl_component intl)
{
    hash_map_destroy(intl);
}

char* intl_translate(intl_component intl, const char *key, const char *locale)
{
    char *locale_key = generate_locale_key(key, locale);

    char *translation = hash_map_get(intl, locale_key, (size_t (*)(const char*))(intl_hash_code));

    if (translation == NULL) {
        free(locale_key);
        locale_key = generate_locale_key(key, DEFAULT_LOCALE);
        translation = hash_map_get(intl, locale_key, (size_t (*)(const char*))(intl_hash_code));
    }

    free(locale_key);

    return (translation == NULL) ? "missing_translation" : translation;
}

char* intl_current_translate(intl_component intl, const char *key)
{
    return intl_translate(intl, key, current_locale);
}

intl_component intl_add_translation(intl_component intl, const char *key, const char *locale, const char *translation)
{
    char *locale_key = generate_locale_key(key, locale);

    intl = hash_map_add(intl, locale_key, translation, (size_t (*)(const char*))(intl_hash_code));

    free(locale_key);

    return intl;
}

intl_component intl_load_locale_file(intl_component intl, const char *file_name, const char *locale)
{
    FILE *fp;
    fp = fopen(file_name,"r");
    if (fp == NULL) {
        perror("Unable to open file!");
        return intl;
    }

    unsigned short int i;
    char line[100];
    char *key = NULL, *translation = NULL;
    while (fgets(line, 100, fp) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        i = 0;
        char *token = strtok(line, "|");
        while (i < 2) {
            if (i == 0) key = token;
            if (i == 1) {
                translation = token;
                intl = intl_add_translation(intl, key, locale, translation);
            }
            token = strtok(NULL, "|");
            i++;
        }
    }

    fclose(fp);

    return intl;
}

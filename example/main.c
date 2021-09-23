#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intl.h"

int main()
{
    intl_component intl = intl_create();

    intl = intl_load_locale_file(intl, "example/en.txt", "en");
    intl = intl_load_locale_file(intl, "example/fr.txt", "fr");
    intl = intl_load_locale_file(intl, "example/it.txt", "it");

    char user_locale[5], user_key[50], user_stop[5];
    bool stop = false;
    while (!stop) {
        printf("Select locale :\n");
        scanf("%s", user_locale);
        intl_set_locale(user_locale);

        printf("Select key to translate in current locale '%s' :\n", intl_get_current_locale());
        scanf("%s", user_key);
        printf("%s\n", intl_current_translate(intl, user_key));

        printf("Continue ? (yes/no)\n");
        scanf("%s", user_stop);
        stop = (strcmp(user_stop, "no") == 0);
    }

    intl_destroy(intl);

    return EXIT_SUCCESS;
}

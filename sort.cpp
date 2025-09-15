#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "sort.h"


int poetic_strcmp(const char* str1, const char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i1 = strlen(str1) - 1,
        i2 = strlen(str2) - 1;

    while (i1 >= 0 && i2 >= 0) {
        if (!isalpha(str1[i1])) {
            i1--;
            continue;
        }
        if (!isalpha(str2[i2])) {
            i2--;
            continue;
        }

        char symb1 = tolower(str1[i1]),
             symb2 = tolower(str2[i2]);
        if (symb1 != symb2)
            return symb1 - symb2;

        i1--;
        i2--;
    }

    return 0;
}


void swap_str(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    char* strtemp = strdup(str1);
    size_t i = 0;
    assert(strtemp != NULL);

    for (i = 0; str2[i] != '\0'; i++)
        str1[i] = str2[i];
    str1[i] = '\0';

    for (i = 0; strtemp[i] != '\0'; i++)
        str2[i] = strtemp[i];
    str2[i] = '\0';

    free(strtemp);
}


void sort_poetically(char text_lines[][60], size_t y, size_t x)
{
    assert(text_lines != NULL);

    for (int i = 1; i < y; i++) {
        int j = i;

        char currstr[x] = {};
        strcpy(currstr, text_lines[j]);

        while (j > 0 && poetic_strcmp(text_lines[j - 1], currstr) > 0) {
            strcpy(text_lines[j], text_lines[j - 1]);
            j--;
        }

        strcpy(text_lines[j], currstr);
    }
}

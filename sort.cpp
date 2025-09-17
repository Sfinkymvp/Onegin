#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "sort.h"
#include "input.h"


int poetic_strcmp(const void* strptr1, const void* strptr2)
{
    assert(strptr1 != NULL);
    assert(strptr2 != NULL);

    const Strpointer sptr1 = *(const Strpointer*)strptr1;
    const Strpointer sptr2 = *(const Strpointer*)strptr2;
    int i1 = sptr1.len - 1;
    int i2 = sptr2.len - 1;

    while (i1 >= 0 && i2 >= 0) {
        assert(sptr1.string != NULL);
        assert(sptr2.string != NULL);

        if (!isalpha(sptr1.string[i1])) {
            i1--;
            continue;
        }
        if (!isalpha(sptr2.string[i2])) {
            i2--;
            continue;
        }

        int symb1 = tolower(sptr1.string[i1]),
             symb2 = tolower(sptr2.string[i2]);
        if (symb1 != symb2)
            return symb1 - symb2;

        i1--;
        i2--;
    }

    return 0;
}


void sort_poetically(Strpointer* text, size_t len)
{
    assert(text != NULL);

    for (size_t i = 1; i < len; i++) {
        size_t j = i;

        Strpointer currptr = text[j];

        while (j > 0 && poetic_strcmp(&text[j - 1], &currptr) > 0) {
            text[j] = text[j - 1];
            j--;
        }

        text[j] = currptr;
    }
}

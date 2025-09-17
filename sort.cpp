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
    int len1 = sptr1.len;
    int len2 = sptr2.len;

    for (int index1 = 0, index2 = 0; index1 < len1 && index2 < len2;) {
        if (!isalpha(sptr1.string[index1])) {
            index1++;
            continue;
        }
        if (!isalpha(sptr2.string[index2])) {
            index2++;
            continue;
        }

        int symbol1 = tolower(sptr1.string[index1]),
            symbol2 = tolower(sptr2.string[index2]);
        if (symbol1 != symbol2)
            return symbol1 - symbol2;

        index1++;
        index2++;
    }

    return 0;
}


int poetic_rstrcmp(const void* strptr1, const void* strptr2)
{
    assert(strptr1 != NULL);
    assert(strptr2 != NULL);

    const Strpointer sptr1 = *(const Strpointer*)strptr1;
    const Strpointer sptr2 = *(const Strpointer*)strptr2;
    int index1 = sptr1.len - 1;
    int index2 = sptr2.len - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (!isalpha(sptr1.string[index1])) {
            index1--;
            continue;
        }
        if (!isalpha(sptr2.string[index2])) {
            index2--;
            continue;
        }

        int symbol1 = tolower(sptr1.string[index1]),
             symbol2 = tolower(sptr2.string[index2]);
        if (symbol1 != symbol2)
            return symbol1 - symbol2;

        index1--;
        index2--;
    }

    return 0;
}


void insertion_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*))
{
    assert(ptr != NULL);
    assert(comp != NULL);

    for (size_t index = 1; index < count; index++) {
        size_t curr_index = index;

        const Strpointer curr_el = ptr[curr_index];

        while (curr_index > 0 && comp(&ptr[curr_index - 1], &curr_el) > 0) {
            ptr[curr_index] = ptr[curr_index - 1];
            curr_index--;
        }

        ptr[curr_index] = curr_el;
    }
}


void swap(Strpointer* ptr1, Strpointer* ptr2)
{
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);

    Strpointer temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


void bubble_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*))
{
    assert(ptr != NULL);
    assert(comp != NULL);

    for (size_t step = count - 1; step > 0; step--) {
        size_t swap_count = 0;

        for (size_t index = 0; index < step; index++)
            if (comp(ptr + index, ptr + index + 1) > 0) {
                swap(ptr + index, ptr + index + 1);
                swap_count++;
            }

        if (!swap_count)
            break;
    }
}


void sort_text(Strpointer* text, size_t count, const Args* arguments)
{
    assert(text != NULL);
    assert(arguments != NULL);

    switch (arguments->sorting_method) {
        case QSORT: {
            if (arguments->reverse_sort == true)
                qsort(text, count, sizeof(Strpointer), poetic_rstrcmp);
            else
                qsort(text, count, sizeof(Strpointer), poetic_strcmp);
            break;
        }

        case INSERTION_SORT: {
            if (arguments->reverse_sort == true)
                insertion_sort(text, count, poetic_rstrcmp);
            else
                insertion_sort(text, count, poetic_strcmp);
            break;
        }

        default: {
            printf("Incorrect sorting argument\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "sort.h"
#include "input.h"


int letter_strcmp(const void* str1, const void* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    const Strpointer s1 = *(const Strpointer*)str1;
    const Strpointer s2 = *(const Strpointer*)str2;
    int len1 = s1.len;
    int len2 = s2.len;

    for (int index1 = 0, index2 = 0; index1 < len1 && index2 < len2;) {
        if (!isalpha(s1.string[index1])) {
            index1++;
            continue;
        }
        if (!isalpha(s2.string[index2])) {
            index2++;
            continue;
        }

        int symbol1 = tolower(s1.string[index1]),
            symbol2 = tolower(s2.string[index2]);
        if (symbol1 != symbol2)
            return symbol1 - symbol2;

        index1++;
        index2++;
    }

    return 0;
}


int letter_rstrcmp(const void* str1, const void* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    const Strpointer s1 = *(const Strpointer*)str1;
    const Strpointer s2 = *(const Strpointer*)str2;
    int index1 = s1.len - 1;
    int index2 = s2.len - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (!isalpha(s1.string[index1])) {
            index1--;
            continue;
        }
        if (!isalpha(s2.string[index2])) {
            index2--;
            continue;
        }

        int symbol1 = tolower(s1.string[index1]),
             symbol2 = tolower(s2.string[index2]);
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

    int (*comparator) (const void*, const void*) = NULL;

    if (arguments->reverse_sort == true)
        comparator = letter_rstrcmp;
    else
        comparator = letter_strcmp;

    assert(comparator != NULL);

    switch (arguments->sorting_method) {
        case QSORT: {
            qsort(text, count, sizeof(Strpointer), comparator);
            break;
        }

        case INSERTION_SORT: {
            insertion_sort(text, count, comparator);
            break;
        }

        case BUBBLE_SORT: {
            bubble_sort(text, count, comparator);
            break;
        }

        case NO_SORT:
            break;

        default:
            printf("Incorrect sorting argument\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "sort.h"
#include "input.h"
#include "args.h"


int letter_strcmp(const void* str1, const void* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    const Line s1 = *(const Line*)str1;
    const Line s2 = *(const Line*)str2;

    for (int index1 = 0, index2 = 0; index1 < s1.length && index2 < s2.length;) {
        if (!isalpha(s1.data[index1])) {
            index1++;
            continue;
        }
        if (!isalpha(s2.data[index2])) {
            index2++;
            continue;
        }

        int symbol1 = tolower(s1.data[index1]),
            symbol2 = tolower(s2.data[index2]);
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

    const Line s1 = *(const Line*)str1;
    const Line s2 = *(const Line*)str2;
    int index1 = s1.length - 1;
    int index2 = s2.length - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (!isalpha(s1.data[index1])) {
            index1--;
            continue;
        }
        if (!isalpha(s2.data[index2])) {
            index2--;
            continue;
        }

        int symbol1 = tolower(s1.data[index1]),
             symbol2 = tolower(s2.data[index2]);
        if (symbol1 != symbol2)
            return symbol1 - symbol2;

        index1--;
        index2--;
    }

    return 0;
}


void insertion_sort(Line* lines, size_t count, int (*comparator) (const void*, const void*))
{
    assert(lines != NULL);
    assert(comparator != NULL);

    for (size_t index = 1; index < count; index++) {
        size_t curr_index = index;

        const Line curr_el = lines[curr_index];

        while (curr_index > 0 && comparator(&lines[curr_index - 1], &curr_el) > 0) {
            lines[curr_index] = lines[curr_index - 1];
            curr_index--;
        }

        lines[curr_index] = curr_el;
    }
}


void swap(Line* line1, Line* line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    Line temp = *line1;
    *line1 = *line2;
    *line2 = temp;
}


void bubble_sort(Line* lines, size_t count, int (*comparator) (const void*, const void*))
{
    assert(lines != NULL);
    assert(comparator != NULL);

    for (size_t step = count - 1; step > 0; step--) {
        size_t swap_count = 0;

        for (size_t index = 0; index < step; index++)
            if (comparator(lines + index, lines + index + 1) > 0) {
                swap(lines + index, lines + index + 1);
                swap_count++;
            }

        if (!swap_count)
            break;
    }
}


void sort_lines(Line* lines, size_t count, Sort_method method, bool reverse_mode)
{
    assert(lines != NULL);

    int (*comparator) (const void*, const void*) = NULL;

    if (reverse_mode == true)
        comparator = letter_rstrcmp;
    else
        comparator = letter_strcmp;

    assert(comparator != NULL);

    switch (method) {
        case SORT_QSORT: {
            qsort(lines, count, sizeof(*lines), comparator);
            break;
        }

        case SORT_INSERTION: {
            insertion_sort(lines, count, comparator);
            break;
        }

        case SORT_BUBBLE: {
            bubble_sort(lines, count, comparator);
            break;
        }

        case SORT_NONE:
            break;

        default:
            printf("Incorrect sorting argument\n");
    }
}

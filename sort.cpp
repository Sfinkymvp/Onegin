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


void copy(void* ptr1, void* ptr2, size_t size)
{
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);

    char* p1 = (char*)ptr1;
    char* p2 = (char*)ptr2;

    while (size >= 8) {
        *(size_t*)p1 = *(size_t*)p2;
        size -= sizeof(size_t);
        p1 += sizeof(size_t);
        p2 += sizeof(size_t);
    }

    while (size >= 4) {
        *(int*)p1 = *(int*)p2;
        size -= sizeof(int);
        p1 += sizeof(int);
        p2 += sizeof(int);
    }

    while (size >= 2) {
        *(short*)p1 = *(short*)p2;
        size -= sizeof(short);
        p1 += sizeof(short);
        p2 += sizeof(short);
    }

    while (size >= 1) {
        *(char*)p1 = *(char*)p2;
        size--;
        p1++;
        p2++;
    }
}


void swap(void* ptr1, void* ptr2, size_t size)
{
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);

    char* p1 = (char*)ptr1;
    char* p2 = (char*)ptr2;

    while (size >= 8) {
        size_t temp = *(size_t*)p1;
        *(size_t*)p1 = *(size_t*)p2;
        *(size_t*)p2 = temp;
        size -= sizeof(size_t);
        p1 += sizeof(size_t);
        p2 += sizeof(size_t);
    }

    while (size >= 4) {
        int temp = *(int*)p1;
        *(int*)p1 = *(int*)p2;
        *(int*)p2 = temp;
        size -= sizeof(int);
        p1 += sizeof(int);
        p2 += sizeof(int);
    }

    while (size >= 2) {
       short temp = *(short*)p1;
        *(short*)p1 = *(short*)p2;
        *(short*)p2 = temp;
        size -= sizeof(short);
        p1 += sizeof(short);
        p2 += sizeof(short);
    }

    while (size >= 1) {
        char temp = *(char*)p1;
        *(char*)p1 = *(char*)p2;
        *(char*)p2 = temp;
        size--;
        p1++;
        p2++;
    }
}


void insertion_sort(void* ptr, size_t count, size_t size, int (*comparator) (const void*, const void*))
{
    assert(ptr != NULL);
    assert(comparator != NULL);

    char* base = (char*)ptr;

    for (size_t index = 1; index < count; index++) {
        size_t curr_index = index;

        void* curr_el = calloc(1, size);

        assert(curr_el != NULL);

        copy(curr_el, base + curr_index * size, size);

        while (curr_index > 0 && comparator(base + (curr_index - 1) * size, curr_el) > 0) {
            copy(base + curr_index * size, base + (curr_index - 1) * size, size);
            curr_index--;
        }

        copy(base + curr_index * size, curr_el, size);

        free(curr_el);
    }
}


void bubble_sort(void* ptr, size_t count, size_t size, int (*comparator) (const void*, const void*))
{
    assert(ptr != NULL);
    assert(comparator != NULL);

    char* base = (char*)ptr;

    for (size_t step = count - 1; step > 0; step--) {
        size_t swap_count = 0;

        for (size_t index = 0; index < step; index++)
            if (comparator(base + index * size, base + (index + 1) * size) > 0) {
                swap(base + index * size, base + (index + 1) * size, size);
                swap_count++;
            }

        if (!swap_count)
            break;
    }
}


void sort_lines(Line* lines, size_t count, Sort_method method, int (*comparator) (const void*, const void*))
{
    assert(lines != NULL);
    assert(comparator != NULL);

    switch (method) {
        case SORT_QSORT: {
            qsort(lines, count, sizeof(*lines), comparator);
            break;
        }

        case SORT_INSERTION: {
            insertion_sort(lines, count, sizeof(*lines), comparator);
            break;
        }

        case SORT_BUBBLE: {
            bubble_sort(lines, count, sizeof(*lines), comparator);
            break;
        }

        case SORT_NONE:
            break;

        default:
            printf("Incorrect sorting argument\n");
    }
}

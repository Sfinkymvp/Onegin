#ifndef _SORT_H_
#define _SORT_H_


#include "input.h"
#include "args.h"


int poetic_strcmp(const void* strptr1, const void* strptr2);


int poetic_rstrcmp(const void* strptr1, const void* strptr2);


void insertion_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*));


void swap(Strpointer* ptr1, Strpointer* ptr2);


void bubble_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*));


void sort_text(Strpointer* text, size_t count, const Args* arguments);


#endif

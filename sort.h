#ifndef _SORT_H_
#define _SORT_H_


#include "input.h"
#include "args.h"


/// Сравнение строк с их начала без учета спец. символов и регистра
/// @param str1 Первая строка
/// @param str2 Вторая строка
/// @return >0 - str1 > str2, 0 - str1 = str2, <0 - str1 < str2
int letter_strcmp(const void* str1, const void* str2);


/// Сравнение строк с их конца без учета спец. символов и регистра
/// @param str1 Первая строка
/// @param str2 Вторая строка
/// @return >0 - str1 > str2, 0 - str1 = str2, <0 - str1 < str2
int letter_rstrcmp(const void* str1, const void* str2);


/// Сортировка вставками, средняя сложность O(n^2), быстрее bubble_sort
/// @param ptr Массив со структурами
/// @param count Количество элементов массива
/// @param comp Используемый компаратор (метод сравнения строк)
void insertion_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*));


/// Меняет две структуры местами
/// @param ptr1 1 структура
/// @param ptr2 2 структура
void swap(Strpointer* ptr1, Strpointer* ptr2);


/// Сортировка пузырьком, средняя сложность O(n^2), самая медленная
/// @param ptr Массив со структурами
/// @param count Количество элементов массива
/// @param comp Используемый компаратор (метод сравнения строк)
void bubble_sort(Strpointer* ptr, size_t count, int (*comp) (const void*, const void*));


/// Выбор метода сортировки, метода сравнения строк
/// @param text Массив со структурами
/// @param count Количество элементов массива
/// @param arguments Указатель на структуру, содержащую название метода сравнения строк
void sort_text(Strpointer* text, size_t count, Sorting sorting_method, bool reverse_mode);


#endif

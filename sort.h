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
/// @param lines Массив со структурами
/// @param count Количество элементов массива
/// @param comparator Используемый компаратор (метод сравнения строк)
void insertion_sort(Line* lines, size_t count, int (*comparator) (const void*, const void*));


/// Меняет две структуры местами
/// @param line1 1 структура
/// @param line2 2 структура
void swap(Line* line1, Line* line2);


/// Сортировка пузырьком, средняя сложность O(n^2), самая медленная
/// @param lines Массив со структурами
/// @param count Количество элементов массива
/// @param comparator Используемый компаратор (метод сравнения строк)
void bubble_sort(Line* lines, size_t count, int (*comparator) (const void*, const void*));


/// Выбор метода сортировки, метода сравнения строк
/// @param lines Массив со структурами
/// @param count Количество элементов массива
/// @param method Метод сортировки
/// @param reverse_mode true - сортировка с конца строки; false - с начала
void sort_lines(Line* lines, size_t count, Sort_method method, bool reverse_mode);


#endif

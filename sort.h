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


/// Копирует второй объект в первый
/// @param ptr1 Первый объект
/// @param ptr2 Второй объект
/// @param size Размер объекта
void copy(void* ptr1, void* ptr2, size_t size);


/// Меняет два объекта местами
/// @param ptr1 Первый объект
/// @param ptr2 Второй объект
/// @param size Размер объекта
void swap(void* ptr1, void* ptr2, size_t size);


/// Сортировка вставками, средняя сложность O(n^2), быстрее bubble_sort
/// @param ptr Массив
/// @param count Количество элементов
/// @param size Размер элемента
/// @param comparator Используемый компаратор (метод сравнения строк)
void insertion_sort(void* ptr, size_t count, size_t size, int (*comparator) (const void*, const void*));


/// Сортировка пузырьком, средняя сложность O(n^2), самая медленная
/// @param ptr Массив
/// @param count Количество элементов
/// @param size Размер элемента
/// @param comparator Используемый компаратор (метод сравнения строк)
void bubble_sort(void* ptr, size_t count, size_t size, int (*comparator) (const void*, const void*));


/// Выбор метода сортировки, метода сравнения строк
/// @param lines Массив со структурами
/// @param count Количество элементов массива
/// @param method Метод сортировки
/// @param comparator Метод сравнения строк
void sort_lines(Line* lines, size_t count, Sort_method method, int (*comparator) (const void*, const void*));


#endif

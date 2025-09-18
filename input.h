#ifndef _INPUT_H_
#define _INPUT_H_

#include "args.h"


size_t get_file_size(const char* input_file_name);


/// Создание динамического массива, содержащего текст из файла
/// @param input_file_name Имя файла с исходным текстом
/// @return Указатель на созданный динамический массив (NULL при ошибке создания)
char* initialize_buffer(const char* input_file_name);


/// Изменение размера динамического массива
/// @param text Указатель на массив структур (двойной указатель)
/// @param new_size новый размер динамического массива
/// @return Указатель на измененный массив (NULL при ошибке изменения)
Strpointer* resize_array(Strpointer** text, size_t new_size);


/// Получение количества строк в буфере
/// @param buffer Массив, содержащий текст из файла
/// @return Количество строк
size_t get_string_count(const char* buffer);


/// Создание динамического массива, содержащего указатели на строки из буфера
/// @param text Указатель на массив структур (двойной указатель)
/// @param buffer Массив, содержащий текст из файла
/// @return Количество записанных строк (0 в случае ошибки)
size_t initialize_text(Strpointer** text, const char* buffer);


#endif

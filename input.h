#ifndef _INPUT_H_
#define _INPUT_H_

#include "args.h"


/// Размер файла
/// @param input_filename Имя файла
/// @return Размер в байтах
size_t get_file_size(const char* input_filename);


/// Заменяет все старые символы на новые
/// @param string Строка
/// @param old_char Старый символ
/// @param new_char Новый символ
/// @return Количество замен
size_t str_replace_char(char* string, char old_char, char new_char);


/// Создание динамического массива, содержащего текст из файла
/// @param input_filename Имя файла с исходным текстом
/// @return Указатель на созданный динамический массив (NULL при ошибке создания)
char* initialize_buffer(const char* input_filename);


/// Изменение размера динамического массива
/// @param lines Массив из структур
/// @param new_size новый размер динамического массива
/// @return Указатель на измененный массив (NULL при ошибке изменения)
Line* resize_array(Line** lines, size_t new_size);


/// Получение количества строк в буфере
/// @param buffer Массив, содержащий текст из файла
/// @return Количество строк
size_t get_line_count(const char* buffer);


/// Создание динамического массива, содержащего указатели на строки из буфера
/// @param lines Указатель на массив структур (двойной указатель)
/// @param buffer Массив, содержащий текст из файла
/// @return Количество записанных строк (0 в случае ошибки)
size_t initialize_lines(Line** lines, const char* buffer);


#endif

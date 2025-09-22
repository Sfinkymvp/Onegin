#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include "input.h"


/// Записывает строки в файл
/// @param lines Массив со структурами, содержащими данные о строках
/// @param count Количество строк
/// @param output_filename Имя файла, в который производится запись
/// @param mode Режим открытия файла
/// @return true - строки записаны; false - произошла ошибка
bool load_lines_to_file(const Line* lines, size_t count, const char* output_filename, const char* mode);


/// Записывает буфер в файл
/// @param buffer Буфер
/// @param size Размер буфера
/// @param output_filename Имя файла, в который производится записа
/// @param mode Режим открытия файла
/// @return true - буфер записан; false - произошла ошибка
bool store_buffer_to_file(const char* buffer, size_t size, const char* output_filename, const char* mode);


#endif

#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include "input.h"


/// Записывает строки в файл
/// @param text Массив со структурами, содержащими данные о строках
/// @param count Количество строк
/// @param output_file_name Имя файла, в который производится запись
/// @return true - строки записаны; false - произошла ошибка
bool load_text_to_file(const Strpointer* text, size_t count, const char* output_file_name);


#endif

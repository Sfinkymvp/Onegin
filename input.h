#ifndef _INPUT_H_
#define _INPUT_H_


/// Начальный размер для создания динамического массива
const int START_SIZE = 32;


/// Удобный способ хранения указателя на строку из буфера и длины этой строки
typedef struct {
    const char* string;     ///< Указатель на строку из буфера
    int len;                ///< Длина строки
} Strpointer;


/// Создание динамического массива, содержащего текст из файла
/// @param input_file_name Имя файла с исходным текстом
/// @return Указатель на созданный динамический массив (NULL при ошибке создания)
char* initialize_buffer(const char* input_file_name);


/// Изменение размера динамического массива
/// @param text Указатель на массив структур (двойной указатель)
/// @param new_size новый размер динамического массива
/// @return Указатель на измененный массив (NULL при ошибке изменения)
Strpointer* resize_array(Strpointer** text, size_t new_size);


/// Создание динамического массива, содержащего указатели на строки из буфера
/// @param text Указатель на массив структур (двойной указатель)
/// @param buffer Массив, содержащий текст из файла
/// @return Количество записанных строк (0 в случае ошибки)
size_t initialize_text(Strpointer** text, const char* buffer);


#endif

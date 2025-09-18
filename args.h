#ifndef _ARGS_H_
#define _ARGS_H_


/// Названия используемых методов сортировок 
typedef enum {
    QSORT = 0,                   ///< В среднем O(n log(n)), самая быстрая
    INSERTION_SORT = 1,          ///< В среднем O(n^2), медленная
    BUBBLE_SORT = 2,             ///< В среднем O(n^2), самая медленная
    NO_SORT = 3                  ///< Код, обозначающий отсутствие сортировки
} Sorting;


/// Удобный способ хранения указателя на строку из буфера и длины этой строки
typedef struct {
    const char* string;     ///< Указатель на строку из буфера
    int len;                ///< Длина строки
} Strpointer;


typedef struct {
    const char* input_file;      ///< Имя файла с исходным текстом
    const char* output_file;     ///< Имя файла для записи отсортированного текста
    char* buffer;
    Strpointer* text;
    size_t string_count;
} Sorting_information;


typedef struct {
    Sorting_information* array;
    size_t size;
    Sorting sorting_method;
    bool help_mode;
} Data;


/// Обрабатывает аргументы командной строки
/// @param argc Количество аргументов
/// @param argv Массив из указателей на аргументы
/// @return Структура с данными из аргументов командной строки
Data get_data(int argc, char** argv);


/// Справочная информация о программе
extern const char* HELP_TEXT;


#endif

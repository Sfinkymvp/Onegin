#ifndef _ARGS_H_
#define _ARGS_H_


/// Методы сортировки
typedef enum {
    SORT_QSORT = 0,                  ///< Quick Sort
    SORT_INSERTION = 1,              ///< Insertion Sort
    SORT_BUBBLE = 2,                 ///< Bubble Sort
    SORT_NONE = 3                    ///< Без сортировки
} Sort_method;


/// Указатель на строку из буфера и ее длина
typedef struct {
    const char* data;                ///< Указатель на строку
    int length;                      ///< Длина строки
} Line;


/// Информация для обработки одного входного/выходного файла
typedef struct {
    const char* input_filename;      ///< Имя файла с исходным текстом
    const char* output_filename;     ///< Имя файла для записи отсортированного текста
    char* buffer;                    ///< Буфер с содержимым файла
    Line* lines;                     ///< Массив строк
    size_t line_count;               ///< Количество строк
} File_process;


/// Все аргументы программы
typedef struct {
    File_process* processes;         ///< Массив задач по файлам
    size_t process_count;            ///< Количество задач
    Sort_method method;              ///< Метод сортировки
    bool show_help;                  ///< true, если указан --help
} Args;


/// Инициализация структуры для аргументов командной строки
/// @param argc Количество аргументов командной строки
/// @return Структура для аргументов командной строки
Args initialize_args(int argc);


/// Обработка аргументов командной строки
/// @param args Структура для аргументов
/// @param argv Аргументы командной строки
void parse_args(Args* args, const char**argv);


/// Обрабатывает аргументы командной строки
/// @param argc Количество аргументов командной строки
/// @param argv Аргументы командной строки
/// @return Структура с данными из аргументов командной строки
Args get_args(int argc, const char** argv);


/// Обработка, сортировка и вывод данных для процесса
/// @param process Данные о файлах, массивах
/// @param method Метод сортировки
/// @return true - работа с процессом завершена; false - возникла ошибка
bool process_file(File_process* process, Sort_method method);


/// Справочная информация о программе
extern const char* HELP_MESSAGE;


#endif

#ifndef _ARGS_H_
#define _ARGS_H_


typedef enum {
    QSORT = 0,
    INSERTION_SORT = 1
} Sorting;


typedef struct {
    const char* input_file;
    const char* output_file;
    bool help_mode;
    bool reverse_sort;
    Sorting sorting_method;
} Args;


Args parse_args(int argc, char** argv);


extern const char* HELP_TEXT;


#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "args.h"


const char* HELP_TEXT = 
    "Usage: ./osort -i <input_file> -o <output_file> [options]\n"
    "The order of arguments can be changed, but -i and -o are required arguments\n"
    "\n"
    "Options:\n"
    "  -i <input_file>    Entering the input file name\n" 
    "  -o <output_file>   Entering the output file name\n"
    "  --help             Show this help message\n"
    "  --method <name>    Selecting a custom sorting method ('insertion', 'bubble')\n"
    "                     Another name disables the sorting function\n"
    "  --reverse          Sort strings from the end\n";


Data get_data(int argc, char** argv)
{
    assert(argv != NULL);

    Data data = {NULL, 0, QSORT, false};

    data.size = (size_t)argc;
    data.array = (Sorting_information*)calloc(data.size, sizeof(Sorting_information));

    if (data.array == NULL) {
        data.size = 0;
        return data;
    }

    size_t input_files_count = 0,
        output_files_count = 0,
        number_el = 0;

    for (size_t index = 1; index < (size_t)argc; index++) {
        
        if (strcmp(argv[index], "-i") == 0 && index < (size_t)argc - 1) {
            data.array[number_el].input_file = argv[++index];
            input_files_count++;

            if (input_files_count == output_files_count)
                number_el++;

            continue;
        }

        if (strcmp(argv[index], "-o") == 0 && index < (size_t)argc - 1) {
            data.array[number_el].output_file = argv[++index];
            output_files_count++;

            if (input_files_count == output_files_count)
                number_el++;
            continue;
        }

        if (strcmp(argv[index], "--help") == 0) {
            data.help_mode = true;
            break;
        }

        if (strcmp(argv[index], "--method") == 0 && index < (size_t)argc - 1) {
            index++;

            if (strcmp(argv[index], "insertion") == 0)
                data.sorting_method = INSERTION_SORT;
            else if (strcmp(argv[index], "bubble") == 0)
                data.sorting_method = BUBBLE_SORT;
            else
                data.sorting_method = NO_SORT;

            continue;
        }
    }

    if (data.help_mode == true ||
        input_files_count != output_files_count) {
        free(data.array);
        data.size = 0;

        return data;
    }

    data.size = (size_t)number_el;

    Sorting_information* temp = (Sorting_information*)realloc(data.array, data.size * sizeof(Sorting_information));

    if (temp == NULL) {
        free(data.array);
        data.array = NULL;
        data.size = 0;
    } else
        data.array = temp;

    return data;
}


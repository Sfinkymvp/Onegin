#include <stdio.h>
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
    "  --reverse          Sort strings from the end\n";


Args parse_args(int argc, char** argv)
{
    assert(argv != NULL);

    Args arguments = {NULL, NULL, false, QSORT};

    for (int index = 1; index < argc; index++) {
        if (strcmp(argv[index], "-i") == 0 && index < argc - 1) {
            arguments.input_file = argv[++index];
            continue;
        }

        if (strcmp(argv[index], "-o") == 0 && index < argc - 1) {
            arguments.output_file = argv[++index];
            continue;
        }

        if (strcmp(argv[index], "--help") == 0) {
            arguments.help_mode = true;
            continue;
        }

        if (strcmp(argv[index], "--method") == 0 && index < argc - 1) {
            index++;

            if (strcmp(argv[index], "insertion") == 0)
                arguments.sorting_method = INSERTION_SORT;

            if (strcmp(argv[index], "bubble") == 0)
                arguments.sorting_method = BUBBLE_SORT;

            continue;
        }

        if (strcmp(argv[index], "--reverse") == 0) {
            arguments.reverse_sort = true;
        }
    }

    return arguments;
}


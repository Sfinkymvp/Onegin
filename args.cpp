#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "args.h"
#include "input.h"
#include "output.h"
#include "sort.h"


const char* HELP_MESSAGE = 
    "Usage: ./osort -i <input_file> -o <output_file> [options] ...\n"
    "The order of arguments can be changed, but -i and -o are required arguments\n"
    "You can enter any number of files for input and output\n"
    "\n"
    "Options:\n"
    "  -i <input_file>    Entering the input file name\n" 
    "  -o <output_file>   Entering the output file name\n"
    "  --help             Show this help message\n"
    "  --method <name>    Selecting a custom sorting method ('insertion', 'bubble')\n"
    "                     Another name disables the sorting function\n";


Args initialize_args(int argc)
{
    Args args = {NULL, 0, SORT_QSORT, false};

    args.process_count = (size_t)argc;
    args.processes = (File_process*)calloc(args.process_count, sizeof(File_process));

    if (args.processes == NULL)
        args.process_count = 0;

    return args;
}


void parse_args(Args* args, const char** argv)
{
    assert(args != NULL);
    assert(argv != NULL);

    size_t input_files_count = 0,
           output_files_count = 0,
           count_el = 0;

    for (size_t index = 1; index < args->process_count; index++) {
        if (strcmp(argv[index], "-i") == 0 && index < args->process_count - 1) {
            args->processes[count_el].input_filename = argv[++index];
            input_files_count++;

            if (input_files_count == output_files_count)
                count_el++;

        } else if (strcmp(argv[index], "-o") == 0 && index < args->process_count - 1) {
            args->processes[count_el].output_filename = argv[++index];
            output_files_count++;

            if (input_files_count == output_files_count)
                count_el++;

        } else if (strcmp(argv[index], "--help") == 0) {
            args->show_help = true;
            break;

        } else if (strcmp(argv[index], "--method") == 0 && index < args->process_count - 1) {
            index++;

            if (strcmp(argv[index], "insertion") == 0)
                args->method = SORT_INSERTION;
            else if (strcmp(argv[index], "bubble") == 0)
                args->method = SORT_BUBBLE;
            else
                args->method = SORT_NONE;
        }
    }

    if (input_files_count == output_files_count && 
        input_files_count != 0 && args->show_help == false)
        args->process_count = count_el;
    else
        args->process_count = 0;
}


Args get_args(int argc, const char** argv)
{
    assert(argv != NULL);

    Args args = initialize_args(argc); 

    parse_args(&args, argv);    

    if (args.show_help == true || args.process_count == 0) {
        free(args.processes);

        return args;
    }

    File_process* temp = (File_process*)realloc(args.processes,
                                                args.process_count * sizeof(File_process));

    if (temp == NULL) {
        free(args.processes);
        args.processes = NULL;
        args.process_count = 0;
    } else
        args.processes = temp;

    return args;
}


bool process_file(File_process* process, Sort_method method)
{
    assert(process != NULL);
    assert(process->input_filename != NULL);
    assert(process->output_filename != NULL);

    process->buffer = initialize_buffer(process->input_filename);

    if (process->buffer == NULL) {
        printf("Error initializing buffer\n");
        return false;
    }

    process->line_count = initialize_lines(&process->lines,
                                            process->buffer);
   
    if (process->line_count == 0) {
        printf("Error initializing lines\n");
        return false;
    }

    assert(process->lines != NULL);

    sort_lines(process->lines, process->line_count, method, false);
    if (!load_lines_to_file(process->lines,
                            process->line_count,
                            process->output_filename, "w")) {
       printf("Error writing to file\n");
       return false;
    }

    sort_lines(process->lines, process->line_count, method, true);
    load_lines_to_file(process->lines,
                       process->line_count,
                       process->output_filename, "a");

    store_buffer_to_file(process->buffer, process->output_filename, "a");

    return true;
}

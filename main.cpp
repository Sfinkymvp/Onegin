#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"
#include "output.h"
#include "sort.h"
#include "args.h"


int main(int argc, const char** argv)
{   
    assert(argv != NULL);

    Args args = get_args(argc, argv);

    if (args.show_help == true) {
        printf("%s", HELP_MESSAGE);
        return 0;
    }

    if (args.process_count == 0) {
        assert(args.processes != NULL);

        printf("Error processing arguments\n");
        return 1;
    }

    assert(args.processes != NULL);
    assert(args.process_count != 0);
   
    for (size_t index = 0; index < args.process_count; index++)
        if (!process_file(&args.processes[index], args.method)) {
            printf("Error while processing data\n"
                   "Input file name:  %s\nOutput file name: %s\n",
                   args.processes[index].names.input_filename,
                   args.processes[index].names.output_filename);
            break;
        }

    for (size_t index = 0; index < args.process_count; index++) {
        free(args.processes[index].buffer);
        free(args.processes[index].lines);
    }

    free(args.processes);

    return 0;
}

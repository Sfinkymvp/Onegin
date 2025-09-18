#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"
#include "output.h"
#include "sort.h"
#include "args.h"


int main(int argc, char** argv)
{   
    Args arguments = parse_args(argc, argv);

    if (arguments.help_mode == true) {
        printf("%s", HELP_TEXT);
        return 0;
    }

    if (arguments.input_file == NULL || arguments.output_file == NULL) {
        printf("You forgot to enter the required arguments, see --help\n");
        return 1;
    }

    char* buffer = initialize_buffer(arguments.input_file);

    if (buffer == NULL) {
        printf("Error initializing buffer\n");
        return 1;
    }

    Strpointer* text = NULL;
    size_t string_count = initialize_text(&text, buffer);
   
    if (string_count == 0) {
        printf("Error initializing text\n");
        return 1;
    }

    sort_text(text, string_count, &arguments);

    assert(text != NULL);
    assert(buffer != NULL);

    if (!load_text_to_file(text, string_count, arguments.output_file))
       printf("Error writing to file\n");

    free(buffer);
    free(text);

    return 0;
}

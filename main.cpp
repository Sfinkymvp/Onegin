#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"
#include "output.h"
#include "sort.h"




int main(int argc, char** argv)
{   
    char* input_file_name = NULL;
    char* output_file_name = NULL;

    if (argc == 3) {
        input_file_name = argv[1];
        output_file_name = argv[2];
    } else {
        printf("The number of arguments is incorrect\n");
        return 1;
    }

    assert(input_file_name != NULL);
    assert(output_file_name != NULL);

    char* buffer = NULL;
    Strpointer* text = NULL;

    initialize_buffer(&buffer, input_file_name);

    if (buffer == NULL) {
        printf("Error initializing buffer\n");
        return 1;
    }

    size_t len = initialize_text(&text, buffer);
    
    if (len == 0) {
        printf("Error initializing text\n");
        return 1;
    }

    sort_poetically(text, len);

    if (!load_text_to_file(text, len, output_file_name))
        printf("Error writing to file\n");

    assert(buffer != NULL);
    assert(text != NULL);

    free(buffer);
    free(text);

    return 0;
}

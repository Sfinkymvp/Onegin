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
    assert(argv != NULL);

    Data data = get_data(argc, argv);

    if (data.help_mode == true) {
        printf("%s", HELP_TEXT);
        return 0;
    }

    if (data.array == NULL || data.size == 0) {
        printf("Error processing arguments\n");
        return 1;
    }

    assert(data.array != NULL);
    assert(data.size != 0);

    for (size_t index = 0; index < data.size; index++) {
        assert(data.array[index].input_file != NULL &&
               data.array[index].output_file != NULL);

        data.array[index].buffer = initialize_buffer(data.array[index].input_file);

        if (data.array[index].buffer == NULL) {
            printf("Error initializing buffer\n");
            break;
        }

        data.array[index].string_count = initialize_text(&data.array[index].text,
                                                          data.array[index].buffer);
       
        if (data.array[index].string_count == 0) {
            printf("Error initializing text\n");
            break;
        }

        assert(data.array[index].text != NULL);

        sort_text(data.array[index].text, data.array[index].string_count, data.sorting_method, false);
        if (!load_text_to_file(data.array[index].text,
             data.array[index].string_count,
             data.array[index].output_file, "w")) {
           printf("Error writing to file\n");
           break;
        }

        sort_text(data.array[index].text, data.array[index].string_count, data.sorting_method, true);
        load_text_to_file(data.array[index].text,
                          data.array[index].string_count,
                          data.array[index].output_file, "a");

        store_buffer_to_file(data.array[index].buffer, data.array[index].output_file, "a");
    }
     
    for (size_t index = 0; index < data.size; index++) {
        free(data.array[index].buffer);
        free(data.array[index].text);
    }
    free(data.array);

    printf("Exit\n");
    
    return 0;
}

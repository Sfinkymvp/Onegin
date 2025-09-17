#include <stdio.h>
#include <assert.h>

#include "output.h"
#include "input.h"


bool load_text_to_file(const Strpointer* text, size_t count, const char* output_file_name)
{
    assert(text != NULL);
    assert(output_file_name != NULL);

    FILE* out = fopen(output_file_name, "w");

    if (out == NULL)
        return false;

    for (size_t arr_index = 0; arr_index < count; arr_index++)
        for (size_t str_index = 0; str_index < (size_t)text[arr_index].len; str_index++) 
            fprintf(out, "%c", text[arr_index].string[str_index]);

    if (fclose(out) == EOF)
        return false;

    return true;
}

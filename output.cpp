#include <stdio.h>
#include <assert.h>

#include "output.h"
#include "input.h"


bool load_text_to_file(const Strpointer* text, size_t len, const char* output_file_name)
{
    assert(text != NULL);
    assert(output_file_name != NULL);

    FILE* out = fopen(output_file_name, "w");

    if (out == NULL)
        return false;

    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < (size_t)text[i].len; j++)
            fprintf(out, "%c", text[i].string[j]);

    if (fclose(out) == EOF)
        return false;

    return true;
}


#include <stdio.h>
#include <assert.h>

#include "output.h"
#include "input.h"


bool load_lines_to_file(const Line* lines, size_t count, const char* output_filename, const char* mode)
{
    assert(lines != NULL);
    assert(output_filename != NULL);
    assert(mode != NULL);

    FILE* out = fopen(output_filename, mode);

    if (out == NULL)
        return false;

    for (size_t lines_index = 0; lines_index < count; lines_index++)
        for (size_t index = 0; index < (size_t)lines[lines_index].length; index++) 
            fprintf(out, "%c", lines[lines_index].data[index]);
    fprintf(out, "\n");

    if (fclose(out) == EOF)
        return false;

    return true;
}


bool store_buffer_to_file(const char* buffer, const char* output_filename, const char* mode)
{
    assert(buffer != NULL);
    assert(output_filename != NULL);
    assert(mode != NULL);

    FILE* out = fopen(output_filename, mode);

    if (out == NULL)
        return false;

    fprintf(out, "%s", buffer);

    if (fclose(out) == EOF)
        return false;

    return true;
}

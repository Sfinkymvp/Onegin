#include <stdio.h>
#include <assert.h>

#include "output.h"


bool load_lines_to_file(const char text_lines[][60], size_t y, const char* file_name)
{
    assert(text_lines != NULL);
    assert(file_name != NULL);

    FILE* out = fopen(file_name, "w");

    if (out == NULL)
        return false;

    for (size_t i = 0; i < y; i++)
        fputs(text_lines[i], out);

    if (fclose(out) == EOF)
        return false;

    return true;
}

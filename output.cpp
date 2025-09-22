#include <stdio.h>
#include <string.h>
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

    for (size_t index = 0; index < count; index++)
        fprintf(out, "%s\n", lines[index].data);

    if (fclose(out) == EOF)
        return false;

    return true;
}


bool store_buffer_to_file(const char* buffer, size_t size, const char* output_filename, const char* mode)
{
    assert(buffer != NULL);
    assert(output_filename != NULL);
    assert(mode != NULL);

    FILE* out = fopen(output_filename, mode);

    printf("%zu\n", size);

    if (out == NULL)
        return false;

    for (size_t index = 0; index < size; index += strlen(buffer + index) + 1)
        fprintf(out, "%s\n", buffer + index);

    if (fclose(out) == EOF)
        return false;

    return true;
}

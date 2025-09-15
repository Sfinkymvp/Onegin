#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "input.h"


bool read_file_to_array(char text_lines[][60], size_t y, size_t x, const char* file_name)
{
    assert(text_lines != NULL);
    assert(file_name != NULL);

    FILE* in = fopen(file_name, "r");
    size_t i = 0;

    if (in == NULL)
        return false;

    for (i = 0; i < y && fgets(text_lines[i], x, in) != NULL; i++)
        ;

    size_t end_index = strlen(text_lines[i - 1]);
/*    if (text_lines[i - 1][end_index - 1] != '\n') {
        text_lines[i - 1][end_index] = '\n';
        text_lines[i - 1][end_index + 1] = '\0';
    }*/

    if (fclose(in) == EOF)
        return false;

    return true;
}

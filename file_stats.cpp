#include <stdio.h>
#include <assert.h>

#include "file_stats.h"


ssize_t count_lines_in_file(const char* file_name)
{
    assert(file_name != NULL);

    FILE* in = fopen(file_name, "r");
    ssize_t count = 0;

    if (in == NULL)
        return -1;

    for (int symb = getc(in); symb != EOF; symb = getc(in))
        count += (symb == '\n');

    if (fclose(in) == EOF)
        return -1;

    return count + 1;
}


ssize_t find_max_line_length(const char* file_name)
{
    assert(file_name != NULL);

    FILE* in = fopen(file_name, "r");
    ssize_t max_length = 0;

    if (in == NULL)
        return -1;
 
    for (int symb = getc(in), i = 0; symb != EOF; symb = getc(in), i++)
        if (symb == '\n') {
            if (i > max_length)
                max_length = i;
            i = 0;
        }

    if (fclose(in) == EOF)
        return -1;

    return max_length;
}

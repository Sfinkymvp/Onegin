#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "input.h"


size_t get_file_size(const char* input_filename)
{
    assert(input_filename != NULL);

    struct stat buf = {};

    if (stat(input_filename, &buf) == -1)
        return 0;

    return (size_t)buf.st_size;
}


char* initialize_buffer(const char* input_filename)
{
    assert(input_filename != NULL);

    FILE* in = fopen(input_filename, "r");

    if (in == NULL) {
        return NULL;
    }

    size_t size = get_file_size(input_filename) + 1;
    if (size == 0)
        return NULL;

    char* buffer  = (char*)calloc(size, 1);
    
    if (buffer == NULL)
        return NULL;

    fread(buffer, 1, size - 1, in);
    buffer[size - 1] = '\0';

    if (fclose(in) != 0) {
        free(buffer);
        buffer = NULL;
    }

    return buffer;
}


size_t get_line_count(const char* buffer)
{
    assert(buffer != NULL);

    size_t count = 0;

    for (size_t index = 0; buffer[index] != '\0'; index++)
        if (buffer[index] == '\n')
            count++;

    return count + 1;
}


size_t initialize_lines(Line** lines, const char* buffer)
{
    assert(lines != NULL);
    assert(buffer != NULL);

    size_t line_count = get_line_count(buffer);
    size_t number_element = 0;
    *lines = (Line*)calloc(line_count, sizeof(Line));

    if (*lines == NULL)
        return 0;
   
    (*lines)[number_element++].data = buffer;

    for (size_t index = 0; true; index++) {
        Line* last_element = &(*lines)[number_element - 1];

        if (buffer[index] == '\0') {
            last_element->length = (int)(buffer + index - last_element->data);
            break; 
        }

        Line* curr_element = &(*lines)[number_element];

        if (buffer[index] == '\n') {
            curr_element->data = buffer + index + 1;
            last_element->length = (int)(curr_element->data - last_element->data);
            number_element++;
        }
    }

    return line_count;
}

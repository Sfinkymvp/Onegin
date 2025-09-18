#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "input.h"


size_t get_file_size(const char* input_file_name)
{
    assert(input_file_name != NULL);

    struct stat buf = {};

    if (stat(input_file_name, &buf) == -1)
        return 0;

    return (size_t)buf.st_size;
}


char* initialize_buffer(const char* input_file_name)
{
    assert(input_file_name != NULL);

    FILE* in = fopen(input_file_name, "r");

    if (in == NULL) {
        return NULL;
    }

    size_t size = get_file_size(input_file_name) + 1;
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


size_t get_string_count(const char* buffer)
{
    assert(buffer != NULL);

    size_t count = 0;

    for (size_t index = 0; buffer[index] != '\0'; index++)
        if (buffer[index] == '\n')
            count++;

    return count + 1;
}


size_t initialize_text(Strpointer** text, const char* buffer)
{
    assert(text != NULL);
    assert(buffer != NULL);

    size_t array_len = get_string_count(buffer);
    size_t number_element = 0;
    *text = (Strpointer*)calloc(array_len, sizeof(Strpointer));

    if (*text == NULL)
        return 0;
   
    (*text)[number_element++].string = buffer;

    for (size_t index = 0; true; index++) {
        Strpointer* last_element = &(*text)[number_element - 1];

        if (buffer[index] == '\0') {
            last_element->len = (int)(buffer + index - last_element->string);
            break; 
        }

        Strpointer* curr_element = &(*text)[number_element];

        if (buffer[index] == '\n') {
            curr_element->string = buffer + index + 1;
            last_element->len = (int)(curr_element->string - last_element->string);
            number_element++;
        }
    }

    return array_len;
}

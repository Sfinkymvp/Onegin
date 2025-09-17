#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"


char* initialize_buffer(const char* input_file_name)
{
    assert(input_file_name != NULL);

    char* buffer = NULL;
    FILE* in = fopen(input_file_name, "r");

    if (in == NULL) {
        return NULL;
    }

    fseek(in, 0, SEEK_END);
    size_t size = (size_t)ftell(in) + 1;
    fseek(in, 0, SEEK_SET);

    buffer = (char*)calloc(size, 1);
    
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


Strpointer* resize_array(Strpointer** text, size_t new_size)
{
    Strpointer* temp = (Strpointer*)realloc(*text, new_size * sizeof(Strpointer));

    if (temp == NULL) {
        free(*text);
    }

    return temp;
}


size_t initialize_text(Strpointer** text, const char* buffer)
{
    assert(text != NULL);
    assert(buffer != NULL);

    size_t array_len = START_SIZE;
    size_t count_elements = 1;
    *text = (Strpointer*)calloc(array_len, sizeof(Strpointer));

    if (*text == NULL)
        return 0;
   
    (*text)[0].string = buffer;

    for (size_t i = 0; true; i++) {
        if (count_elements >= array_len) {
            array_len *= 2;

            *text = resize_array(text, array_len);
            if (*text == NULL)
                return 0;
        }

        Strpointer* last_element = &(*text)[count_elements - 1];

        if (buffer[i] == '\0') {
            last_element->len = (int)(buffer + i - last_element->string);
            break; 
        }

        Strpointer* curr_element = &(*text)[count_elements];

        if (buffer[i] == '\n') {
            curr_element->string = buffer + i + 1;
            last_element->len = (int)(curr_element->string - last_element->string);
            count_elements++;
        }
    }

    array_len = count_elements; 

    *text = resize_array(text, array_len);
    if (*text == NULL)
        return 0;

    return array_len;
}


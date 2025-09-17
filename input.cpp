#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input.h"


long get_file_size(const char* input_file_name)
{
    assert(input_file_name != NULL);

    FILE* fp = fopen(input_file_name, "r");

    if (fp == NULL)
        return -1;

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if (fclose(fp) != 0)
        return -1;

    return size;
}


void initialize_buffer(char** buffer, const char* input_file_name)
{
    assert(input_file_name != NULL);

    FILE* in = fopen(input_file_name, "r");

    if (in == NULL) {
        *buffer = NULL;
        return;
    }

    fseek(in, 0, SEEK_END);
    size_t size = (size_t)ftell(in) + 1;
    fseek(in, 0, SEEK_SET);

    *buffer = (char*)calloc(size, 1);
    
    if (*buffer == NULL)
        return;

    fread(*buffer, 1, size - 1, in);
    (*buffer)[size - 1] = '\0';

    fclose(in);
}


size_t initialize_text(Strpointer** text, const char* buffer)
{
    assert(buffer != NULL);

    size_t strcnt = START_SIZE;
    size_t n = 1;
    *text = (Strpointer*)calloc(strcnt, sizeof(Strpointer));

    if (*text == NULL)
        return 0;
   
    (*text)[0].string = buffer;

    for (size_t i = 0; true; i++) {
        if (n >= strcnt) {
            strcnt *= 2;
            Strpointer* temp = (Strpointer*)realloc(*text, strcnt * sizeof(Strpointer));

            if (temp == NULL) {
                free(*text);
                *text = NULL;
                return 0;
            }
            *text = temp;
        }

        if (buffer[i] == '\0') {
            (*text)[n - 1].len = (int)(buffer + i - (*text)[n - 1].string);
            break; 
        }

        if (buffer[i] == '\n') {
            (*text)[n].string = buffer + i + 1;
            (*text)[n - 1].len = (int)((*text)[n].string - (*text)[n - 1].string);
            n++;
        }
    }

    strcnt = n; 
    *text = (Strpointer*)realloc(*text, strcnt * sizeof(Strpointer));

    return strcnt;
}

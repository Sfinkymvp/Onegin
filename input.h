#ifndef _INPUT_H_
#define _INPUT_H_


const int START_SIZE = 32;


typedef struct {
    const char* string;
    int len;
} Strpointer;


long get_file_size(const char* input_file_name);


void initialize_buffer(char** buffer, const char* input_file_name);


size_t initialize_text(Strpointer** text, const char* buffer);


#endif

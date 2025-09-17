#ifndef _INPUT_H_
#define _INPUT_H_


const int START_SIZE = 32;


typedef struct {
    const char* string;
    int len;
} Strpointer;


char* initialize_buffer(const char* input_file_name);


Strpointer* resize_array(Strpointer** text, size_t new_size);


size_t initialize_text(Strpointer** text, const char* buffer);


#endif

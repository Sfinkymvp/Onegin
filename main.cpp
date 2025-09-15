#include <stdio.h>
#include <string.h>

#include "input.h"
#include "output.h"
#include "sort.h"
#include "file_stats.h"


const size_t MAX_FILE_NAME_LEN = 50;


int main()
{
    char file_name[MAX_FILE_NAME_LEN];

    printf("Enter input file name:\n");
    
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';

    printf("after fgets\n"); 

    const ssize_t y = count_lines_in_file(file_name);
    const ssize_t x = find_max_line_length(file_name);

    printf("after count_lines_in_file\n");
    printf("x = %zd, y = %zd\n", x, y);

    char text_lines[y][60] = {};

    read_file_to_array(text_lines, y, x, file_name);

    printf("after read_file_to_array\n");

    sort_poetically(text_lines, y, x);

    printf("after sort_poetically\n");
    printf("Enter output file name:\n");

    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';

    load_lines_to_file(text_lines, y, file_name);

    return 0;
}

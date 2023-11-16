#include "include/count.h"
#include <stdio.h>

int main(int argc,  char *argv[]) {

    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file contents
    char *buffer = malloc(size + 1);
    if (!buffer) {
        printf("Could not allocate memory for file contents.\n");
        return 1;
    }

    // Read file contents into buffer
    fread(buffer, 1, size, fp);
    buffer[size] = '\0';

    printf("Lines: %d\n", count_lines(buffer));
    printf("Words: %d\n", count_words(buffer));
    printf("Characters: %d\n", count_characters(buffer));

    free(buffer);
    fclose(fp);

    return 0;
}
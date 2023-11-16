#include <stdlib.h>
#include "include/count.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    int print_chars = 0;

    while ((opt = getopt(argc, argv, "m")) != -1) {
        if (opt == 'm') {
            print_chars = 1;
        } else {
            printf("Usage: %s [-m] <filename1> <filename2> ...\n", argv[0]);
            return 1;
        }
    }

    for (int i = optind; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            printf("Could not open file %s\n", argv[i]);
            continue;
        }

        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char *buffer = malloc(size + 1);
        if (!buffer) {
            printf("Could not allocate memory for file contents.\n");
            fclose(fp);
            continue;
        }

        fread(buffer, 1, size, fp);
        buffer[size] = '\0';

        printf("File: %s\n", argv[i]);
        if (print_chars) {
            printf("Characters: %d\n", count_characters(buffer));
        } else {
            printf("Lines: %d\n", count_lines(buffer));
            printf("Words: %d\n", count_words(buffer));
        }

        free(buffer);
        fclose(fp);
    }

    return 0;
}
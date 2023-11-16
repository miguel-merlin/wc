#include <stdio.h>
#include "count.h"
#include <string.h>

void test_count_lines() {
    char *s = "line1\nline2\nline3\n";
    int result = count_lines(s);
    if (result == 3) {
        printf("count_lines passed\n");
    } else {
        printf("count_lines failed: expected 3, got %d\n", result);
    }
}

void test_count_words() {
    char *s = "word1 word2 word3";
    int result = count_words(s);
    if (result == 3) {
        printf("count_words passed\n");
    } else {
        printf("count_words failed: expected 3, got %d\n", result);
    }
}

void test_count_characters() {
    char *s = "12345";
    int result = count_characters(s);
    if (result == 5) {
        printf("count_characters passed\n");
    } else {
        printf("count_characters failed: expected 5, got %d\n", result);
    }
}

int main() {
    test_count_lines();
    test_count_words();
    test_count_characters();
    return 0;
}
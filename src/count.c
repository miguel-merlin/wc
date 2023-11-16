#include "include/count.h"

int count_lines(char *s) {
   
    /*
    Count the number of liunes in a string. A line is defined as a sequence of
    characters followed by a newline character ('\n').
    */

    int lines = 0;
    while (*s != '\0')
    {
        if (*s == '\n')
        {
            lines++;
        }
        s++;
    }
    return lines;
}

int count_words(char *s) {

    /*
    Count the number of words in a string. A word is defined as a sequence of
    non-whitespace characters.
    */

    int words = 0;
    int in_word = 0;
    while (*s)
    {
        if (isspace(*s))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            words++;
        }
        s++;
    }
    return words;
}

int count_characters(char *s) {

    /*
    Count the number of characters in a string. 
    */

    int characters = 0;
    while (*s)
    {
        characters++;
        s++;
    }
    return characters;
}
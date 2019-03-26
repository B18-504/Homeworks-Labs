#ifndef strings_h
#define strings_h
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct string {
    char str[255];
};

void string_set(struct string* word) {
    int i = 0, ch;
    while ((ch = getchar()) != '\n') {
        word->str[i] = ch;
        i += 1;
    }
    word->str[i] = '\0';
}

void string_print(struct string* word) {
    int i = 0;
    while (word->str[i] != '\0') {
        printf("%c", word->str[i]);
        i += 1;
    }
}

struct string string_concat(struct string* word1, struct string* word2) {
    int i = 0, j = 0;
    struct string mem;
    while (word1->str[i] != '\0') {
        mem.str[i] = word1->str[i];
        i += 1;
    }
    while (word2->str[j] != '\0') {
        mem.str[i] = word2->str[j];
        i += 1;
        j += 1;
    }
    mem.str[i] = '\0';
    return mem;
}

void string_set_random(struct string* word, long int t) {
    int i;
    srand((unsigned)t);
    
    char ch;
    int length;
    length = (rand() % (8 - 4)) + 4;
    while ((length > 8) || (length < 4)) {
        length = (rand() % (8 - 4)) + 4;
    }
    
    for (i = 0; i < length; i += 1) {
        ch = (rand() % (122 - 97)) + 97;
        while (((int)ch > 122) || ((int)ch < 97)) {
            ch = (rand() % (122 - 97)) + 97;
        }
        word->str[i] = (char)ch;
    }
    word->str[i] = '\0';
}

int string_compare(struct string* word1, struct string* word2) {
    int i = 0;
    
    while ((word1->str[i] != '\0') || (word2->str[i] != '\0')) {
        if (strncmp(&word1->str[i], &word2->str[i], 1) > 0) {
            return 1;
        }
        if (strncmp(&word1->str[i], &word2->str[i], 1) < 0) {
            return -1;
        }
        i += 1;
    }
    return 0;
}


#endif

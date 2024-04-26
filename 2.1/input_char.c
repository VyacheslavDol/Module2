#include <stdio.h>
#include <string.h>

void input_char(char* word, long size_word){            //функция корректного и удобного ввода с помощью fgets с очисткой буффера
    int c;
    memset(word, 0, size_word);
    fgets(word, size_word, stdin);
    word[strcspn(word, "\n")] = '\0';
    if(strcmp(&word[size_word-2], "\0"))
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}
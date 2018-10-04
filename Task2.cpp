#include <iostream>
#include <algorithm>
#include "string.h"
#include <assert.h>

/**
 * @brief Функция, заменяющая \n на \0
 * @return Строка без символов newline
 */
char* replace_char(char* str, char* strings[], char find, char replace,
                   long size) {
    int k = 1;
    for (int i = 0; i < size; i++) {
        if (*(str + i) == '\n') {
            strings[k++] = (str + i + 1);
            *(str + i) = '\0';
        }
    }
    return str;
}

/**
 * @brief Компаратор для функции std::sort
 * @return Булева переменная, указывающая компаратору, как нужно отсортировать две строки
 */
bool StringCompare(const char* a, const char* b) {
    if (a == nullptr || b == nullptr) {
        return a == nullptr;
    }
    size_t len1 = strlen((const char*)a);
    if (len1 == 0) return true;
    size_t len2 = strlen((const char*)b);
    if (len2 == 0) return false;

    for (size_t i = len1 - 1, j = len2 - 1; i > 0 && j > 0; i--, j--) {
        char a_letter = a[i];
        char b_letter = b[j];
        if (a_letter < b_letter) {
            return true;
        } else if (a_letter > b_letter) {
            return false;
        }
        if (i == 0) return true;
        if (j == 0) return false;
    }
    return true;
}

/**
 * @brief Основной метод, связанный с обработкой и сортировкой текста
 * @param ptrFile - указатель на файл
 */
void TextInit(FILE* ptrFile) {
    fseek(ptrFile, 0, SEEK_END);
    long size = ftell(ptrFile);
    rewind(ptrFile);
    char* buffer = (char*)malloc(sizeof(char*) * (size + 2));
    if (!buffer) {
        printf("Failed to malloc\n");
        exit(1);
    }
    fread(buffer, 1, size, ptrFile);
    assert(buffer != NULL);
    buffer = buffer - size;
    char* strings[4430];
    for (int i = 0; i < 4430; i++)
        strings[i] = (char*)malloc(256 * sizeof(char*));
    for (int i = 0; i < 4430; i++) {
        strings[i] = 0;
    }
    char to_replace = '\n';
    char replacement = '\0';
    replace_char(buffer, strings, to_replace, replacement, size);
    strings[0] = buffer;
    std::sort(strings, strings + 4429, StringCompare);
    FILE* output = fopen("../hamlet_sorted.txt", "w");
    for (int i = 0; i < 64; i++) std::cout << strings[i];
    for (int i = 0; i < 4430; i++) {
        fputs(strings[i], output);
        fputs("\n", output);
    }
    fclose(output);
    for (int i = 0; i < 4430; i++) {
        free(strings[i]);
    }
    free(buffer);
}

/**
 * @brief Entry point
 * @return Program exit status
 */
int main() {
    FILE* ptrFile = fopen("../hamlet.txt", "r");
    if (!ptrFile) {
        printf("Failed to open file\n");
        exit(1);
    }
    TextInit(ptrFile);
    fclose(ptrFile);
    return 0;
}
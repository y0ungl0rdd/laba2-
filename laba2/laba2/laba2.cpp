#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "process.h"
using namespace std;

int proga1() {
    int length = 0;
    char ch;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        printf("Память не выделена.");
        exit(0);
    }

    cout << "Введите строку (введите '.' для завершения ввода):\n";

    while ((ch = getchar()) != '.') {
        str[length++] = ch;

        char* data = (char*)malloc((length + 1) * sizeof(char));
        if (data == NULL) {
            printf("Память не выделена.");
            free(str);
            exit(0);
        }

        for (int i = 0; i < length; i++) {
            data[i] = str[i];
        }
        data[length] = '\0';

        free(str);
        str = data;
    }
    string res = process(str, length);
    cout << res << endl;
}
int proga2() {
    int length = 0;
    int allocatedSize = 5;
    char ch;
    char* str = (char*)calloc(5, sizeof(char));
    if (str == NULL) {
        printf("Память не выделена.");
        exit(0);
    }

    cout << "Введите строку (введите '.' для завершения ввода):\n";
    while ((ch = getchar()) != '.') {
        if (length >= allocatedSize) {
            allocatedSize += 5;
            char* data = (char*)realloc(str, allocatedSize * sizeof(char));

            if (data != NULL) {
                str = data;
            }
            else {
                printf("Память не выделена.");
                free(str);
                exit(0);

            }
        }

        str[length++] = ch;
    }
    str[length] = '\0';
    string res = process(str, length);
    cout << res << endl;

    return 0;
}

int proga3() {
    FILE* final_file;
    FILE* initial_file = fopen("initial_file.txt", "r");
    if (initial_file == NULL) {
        printf("Ошибка открытия файла.");
        return 1;
    }

    char ch;
    int length = 0;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        printf("Память не выделена.");
        exit(0);
    }

    while ((ch = fgetc(initial_file)) != EOF && ch != '.') {
        str[length++] = ch;

        char* data = (char*)malloc((length + 1) * sizeof(char));
        if (data == NULL) {
            printf("Память не выделена.");
            free(str);
            exit(0);
        }

        for (int i = 0; i < length; i++) {
            data[i] = str[i];
        }
        data[length] = '\0';

        free(str);
        str = data;
    }
    fclose(initial_file);

    final_file = fopen("final_file.txt", "w");
    if (initial_file == NULL) {
        printf("Ошибка открытия файла.");
        free(str);
        return 1;
    }

    fputs(process(str, length).c_str(), final_file);
    fclose(final_file);
}
void main() {
    setlocale(LC_ALL, "RU");
    proga3();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_LINE 2048
#define MAX_TEXT 10000

const char delimiters[] = " \t\n\r.,!?:;\"'()[]{}<>";

bool has_double_letters(const char* word) {
    for (int i = 0; word[i] != '\0' && word[i+1] != '\0'; i++) {
        if (word[i] == word[i+1]) {
            return true;
        }
    }
    return false;
}

bool is_symmetric(const char* word) {
    int len = strlen(word);
    if (len < 2) return false;

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (word[i] != word[j]) {
            return false;
        }
    }
    return true;
}

void task1(FILE* fin, FILE* fout) {
    char line[MAX_LINE];
    char extracted[MAX_TEXT] = "";
    char remaining[MAX_TEXT] = "";

    while (fgets(line, sizeof(line), fin)) {
        char *token = strtok(line, delimiters);
        while (token != NULL) {
            if (has_double_letters(token)) {
                strcat(extracted, token);
                strcat(extracted, " ");
            } else {
                strcat(remaining, token);
                strcat(remaining, " ");
            }
            token = strtok(NULL, delimiters);
        }
    }

    fprintf(fout, "--- Залишковий текст ---\n%s\n\n", remaining);
    fprintf(fout, "--- Вилученi слова з пiдвоєнням ---\n%s\n", extracted);
    printf("Обробку завершено. Результати записано у вихiдний файл.\n");
}

void task2(FILE* fin, FILE* fout) {
    char line[MAX_LINE];
    char remaining[MAX_TEXT] = "";
    int max_len = 0;

    while (fgets(line, sizeof(line), fin)) {
        // Створюємо копiю рядка, бо strtok змiнює оригiнал
        char line_copy[MAX_LINE];
        strcpy(line_copy, line); 
        
        char *token = strtok(line_copy, delimiters);
        while (token != NULL) {
            int len = strlen(token);
            if (len > max_len) {
                max_len = len;
            }
            token = strtok(NULL, delimiters);
        }
    }

    // Повертаємо курсор на початок файлу для другого проходу
    rewind(fin);

    // Другий прохiд: вилучаємо слова з максимальною довжиною
    while (fgets(line, sizeof(line), fin)) {
        char *token = strtok(line, delimiters);
        while (token != NULL) {
            if (strlen(token) != max_len) {
                strcat(remaining, token);
                strcat(remaining, " ");
            }
            token = strtok(NULL, delimiters);
        }
    }

    fprintf(fout, "--- Текст пiсля вилучення найдовших слiв (довжина %d) ---\n%s\n", max_len, remaining);
    printf("Обробку завершено. Найдовшi слова вилучено. Результати у вихiдному файлi.\n");
}

void task3(FILE* fin, FILE* fout) {
    char line[MAX_LINE];
    int found_count = 0;

    fprintf(fout, "--- Знайденi симетричнi слова ---\n");
    
    while (fgets(line, sizeof(line), fin)) {
        char *token = strtok(line, delimiters);
        while (token != NULL) {
            if (is_symmetric(token)) {
                fprintf(fout, "%s\n", token);
                found_count++;
            }
            token = strtok(NULL, delimiters);
        }
    }

    if (found_count == 0) {
        fprintf(fout, "Симетричних слiв не знайдено.\n");
    }
    printf("Обробку завершено. Знайдено симетричних слiв: %d.\n", found_count);
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    char in_filename[256];
    char out_filename[256];
    int choice;

    printf("Введiть назву ВХiДНОГО файлу (наприклад, input.txt): ");
    scanf("%255s", in_filename);
    
    printf("Введiть назву ВИХiДНОГО файлу (наприклад, output.txt): ");
    scanf("%255s", out_filename);

    FILE* fin = fopen(in_filename, "r");
    if (fin == NULL) {
        printf("Помилка: не вдалося вiдкрити вхiдний файл '%s'!\n", in_filename);
        return 1;
    }

    FILE* fout = fopen(out_filename, "w");
    if (fout == NULL) {
        printf("Помилка: не вдалося створити вихiдний файл '%s'!\n", out_filename);
        fclose(fin);
        return 1;
    }

    printf("\n======================================\n");
    printf("Оберiть завдання для обробки тексту:\n");
    printf("1 - Вилучити слова з пiдвоєнням лiтер\n");
    printf("2 - Вилучити слова найбiльшої довжини\n");
    printf("3 - Знайти симетричнi слова\n");
    printf("======================================\n");
    printf("Ваш вибiр: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Помилка вводу!\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    switch (choice) {
        case 1:
            task1(fin, fout);
            break;
        case 2:
            task2(fin, fout);
            break;
        case 3:
            task3(fin, fout);
            break;
        default:
            printf("Невiрний вибiр. Програму завершено.\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
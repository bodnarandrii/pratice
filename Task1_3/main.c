#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void task1() {
    printf("\n--- Task 1: Parentheses Balance ---\n");
    printf("Enter text with parentheses:\n> ");
    clear_input_buffer();
    
    char text[1024];
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }

    int stack[1024]; // Стек для зберігання позицій відкриваючих дужок
    int top = -1;
    
    // Масиви для зберігання пар індексів (відкриваюча, закриваюча)
    int pairs_open[1024];
    int pairs_close[1024];
    int pair_count = 0;
    
    int is_balanced = 1; // Прапорець збалансованості

    // Прохід по тексту
    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if (text[i] == '(') {
            stack[++top] = i; // Додаємо індекс відкриваючої дужки у стек
        } else if (text[i] == ')') {
            if (top == -1) {
                // Знайшли закриваючу дужку, але стек порожній - дисбаланс
                is_balanced = 0;
                break;
            }
            // Формуємо пару. Оскільки йдемо зліва направо, закриваючі дужки 
            // автоматично фіксуються за зростанням їхніх позицій.
            pairs_open[pair_count] = stack[top--];
            pairs_close[pair_count] = i;
            pair_count++;
        }
    }

    // Якщо в стеку залишились відкриваючі дужки - дисбаланс
    if (top != -1) {
        is_balanced = 0;
    }

    if (is_balanced) {
        printf("Result: Parentheses are BALANCED.\n");
        printf("Pairs (Position format: [Open] -> [Close]):\n");
        for (int i = 0; i < pair_count; i++) {
            // Виводимо позиції (індексація з 0)
            printf("Pair %d: %d -> %d\n", i + 1, pairs_open[i], pairs_close[i]);
        }
    } else {
        printf("Result: Parentheses are NOT BALANCED.\n");
    }
}

// Завдання 2: Реверс елементів між першим і останнім входженням E
void task2() {
    printf("\n--- Task 2: Reverse between occurrences of E ---\n");
    int n, E;
    
    printf("Enter the number of elements in list: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid list size.\n");
        return;
    }

    int *L = (int*)malloc(n * sizeof(int));
    if (L == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter %d elements (separated by space):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    printf("Enter element E: ");
    scanf("%d", &E);

    int first = -1;
    int last = -1;

    // Знаходимо перше і останнє входження елемента E
    for (int i = 0; i < n; i++) {
        if (L[i] == E) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // Якщо елемент зустрічається хоча б двічі (last > first)
    // і між ними є хоча б один елемент
    if (first != -1 && last != -1 && last - first > 1) {
        int left = first + 1;
        int right = last - 1;
        // Змінюємо порядок елементів між first і last на обернений
        while (left < right) {
            int temp = L[left];
            L[left] = L[right];
            L[right] = temp;
            left++;
            right--;
        }
    }

    // Вивід модифікованого списку (по 5 елементів у рядку)
    printf("\nModified list:\n");
    for (int i = 0; i < n; i++) {
        printf("%8d ", L[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    if (n % 5 != 0) {
        printf("\n");
    }

    free(L); // Звільняємо пам'ять
}

// Завдання 3: Вилучення від'ємних і розміщення їх у кінці в оберненому порядку
void task3() {
    printf("\n--- Task 3: Move negative elements to end in reverse order ---\n");
    int n;

    printf("Enter the number of elements in list: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid list size.\n");
        return;
    }

    int *L = (int*)malloc(n * sizeof(int));
    int *positives = (int*)malloc(n * sizeof(int)); // масив для невід'ємних
    int *negatives = (int*)malloc(n * sizeof(int)); // масив для від'ємних
    
    if (!L || !positives || !negatives) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter %d elements (separated by space):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    int pos_count = 0;
    int neg_count = 0;

    // Розділяємо елементи на два масиви
    for (int i = 0; i < n; i++) {
        if (L[i] < 0) {
            negatives[neg_count++] = L[i];
        } else {
            positives[pos_count++] = L[i];
        }
    }

    int index = 0;
    
    // Спочатку записуємо всі невід'ємні числа в оригінальному порядку
    for (int i = 0; i < pos_count; i++) {
        L[index++] = positives[i];
    }
    
    // Потім записуємо від'ємні числа в оберненому порядку до їхньої появи
    for (int i = neg_count - 1; i >= 0; i--) {
        L[index++] = negatives[i];
    }

    // Вивід результату (по 5 елементів у рядку)
    printf("\nModified list:\n");
    for (int i = 0; i < n; i++) {
        printf("%8d ", L[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    if (n % 5 != 0) {
        printf("\n");
    }

    // Звільнення виділеної пам'яті
    free(L);
    free(positives);
    free(negatives);
}

// Головна функція з меню
int main() {
    int choice;

    do {
        printf("MAIN MENU\n");
        printf("1.Task 1\n");
        printf("2.Task 2\n");
        printf("3.Task 3\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
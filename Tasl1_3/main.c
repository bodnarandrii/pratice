#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};

// Додавання елемента в кінець списку
void append_node(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        printf("%8d ", head->data);
        count++;
        if (count % 5 == 0) printf("\n");
        head = head->next;
    }
    if (count % 5 != 0) printf("\n");
}

void free_list(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void task1() {
    printf("\n--- Task 1: Parentheses Balance ---\n");
    printf("Enter text with parentheses:\n> ");
    clear_input();
    
    char text[1024];
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }

    int stack[1024]; 
    int top = -1;    
    
    int pairs_open[1024];  
    int pairs_close[1024]; 
    int pair_count = 0;
    
    int is_balanced = 1; 

    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if (text[i] == '(') {
            stack[++top] = i; 
        } else if (text[i] == ')') {
            if (top == -1) {
                is_balanced = 0; 
                break;
            }
            pairs_open[pair_count] = stack[top--];
            pairs_close[pair_count] = i;
            pair_count++;
        }
    }

    if (top != -1) {
        is_balanced = 0; 
    }

    if (is_balanced) {
        printf("Result: Parentheses are BALANCED.\n");
        printf("Pairs (Open -> Close):\n");
        for (int i = 0; i < pair_count; i++) {
            printf("Pair %d: %d -> %d\n", i + 1, pairs_open[i], pairs_close[i]);
        }
    } else {
        printf("Result: Parentheses are NOT BALANCED.\n");
    }
}


void task2() {
    printf("\n--- Task 2: Reverse sublist between E ---\n");
    int n, E, val;
    
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    struct Node* L = NULL;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append_node(&L, val);
    }

    printf("Enter element E: ");
    scanf("%d", &E);

    struct Node* first_e = NULL;
    struct Node* last_e = NULL;
    struct Node* curr = L;
    
    while (curr != NULL) {
        if (curr->data == E) {
            if (first_e == NULL) first_e = curr;
            last_e = curr;
        }
        curr = curr->next;
    }

    if (first_e != NULL && last_e != NULL && first_e != last_e && first_e->next != last_e) {
        struct Node* sub_head = first_e->next; // Початок підсписку
        struct Node* prev_last = first_e;
        // Знаходимо елемент ПЕРЕД last_e
        while (prev_last->next != last_e) {
            prev_last = prev_last->next;
        }
        // Відриваємо підсписок від кінця
        prev_last->next = NULL; 

        struct Node* prev = NULL;
        struct Node* current = sub_head;
        struct Node* next = NULL;
        struct Node* reversed_tail = sub_head; // Те, що було початком, стане кінцем

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        struct Node* reversed_head = prev;

        // Вшиваємо перевернутий шматок назад у список
        first_e->next = reversed_head;
        reversed_tail->next = last_e;
    }

    printf("\nModified list:\n");
    print_list(L);
    free_list(L);
}

void task3() {
    printf("\n--- Task 3: Move negatives to end ---\n");
    int n, val;
    
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    struct Node* L = NULL;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append_node(&L, val);
    }
    struct Node* current = L;
    struct Node* prev = NULL;
    struct Node* neg_head = NULL; // Голова для ланцюжка від'ємних

    while (current != NULL) {
        if (current->data < 0) {
            struct Node* temp = current; // Вириваємо вузол з поточного списку
            if (prev == NULL) {
                L = current->next; // Якщо вириваємо перший елемент
            } else {
                prev->next = current->next;
            }
            current = current->next;
            // Чіпляємо його на ПОЧАТОК списку від'ємних (це автоматично розмістить їх у зворотному порядку)
            temp->next = neg_head;
            neg_head = temp;
        } else {
            prev = current;
            current = current->next;
        }
    }

    // Приєднуємо ланцюг від'ємних чисел у кінець списку додатних
    if (L == NULL) {
        L = neg_head;
    } else {
        struct Node* last = L;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = neg_head;
    }

    printf("\nModified list:\n");
    print_list(L);
    free_list(L);
}


int main() {
    int choice;
    while (1) {
        printf("             MAIN MENU\n");
        printf("1. Task 1\n");
        printf("2. Task 2\n");
        printf("3. Task 3\n");
        printf("0. Exit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Critical input error.\n");
            break;
        }

        if (choice == 0) {
            printf("Exiting.\n");
            break;
        } else if (choice == 1) {
            task1();
        } else if (choice == 2) {
            task2();
        } else if (choice == 3) {
            task3();
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}
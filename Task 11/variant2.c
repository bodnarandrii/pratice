#include <stdio.h>
#include <math.h>

// Рекурсивна функція для Завдання 2
// i    - поточний крок
// n    - кінцеве значення
// xi   - значення x на поточному кроці
// yi   - значення y на поточному кроці
double calc_sum2(int i, int n, double xi, double yi) {
    if (i > n) {
        return 0.0; // Базовий випадок
    }
    
    // Обчислюємо поточний доданок суми
    double current_term = xi / (1.0 + fabs(yi));
    
    // Обчислюємо значення для наступного кроку (i+1)
    double next_x = 0.3 * xi;
    double next_y = xi * xi + yi;
    
    // Рекурсивний виклик
    return current_term + calc_sum2(i + 1, n, next_x, next_y);
}

int main() {
    int n;
    
    printf("Введіть натуральне число n для Завдання 2: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Помилка: n має бути натуральним числом (n >= 1).
");
        return 1;
    }

    // Початкові значення для першого кроку: 
    // i=1, x1=1.0, y1=1.0
    double sum2 = calc_sum2(1, n, 1.0, 1.0);

    printf("Результат для завдання 2: %lf\n", sum2);

    return 0;
}

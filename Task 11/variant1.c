#include <stdio.h>
#include <math.h>

// Рекурсивна функція для Завдання 1
// k    - поточний крок
// n    - кінцеве значення
// ak   - значення a на поточному кроці
// bk   - значення b на поточному кроці
// fact - значення факторіала (k!)
double calc_sum1(int k, int n, double ak, double bk, double fact) {
    if (k > n) {
        return 0.0; // Базовий випадок
    }
    
    // Обчислюємо поточний доданок суми
    double current_term = (ak * bk) / fact;
    
    // Обчислюємо значення для наступного кроку (k+1)
    double next_a = 0.5 * (sqrt(bk) + 0.5 * sqrt(ak));
    double next_b = 2.0 * ak * ak + bk;
    
    // Рекурсивний виклик
    return current_term + calc_sum1(k + 1, n, next_a, next_b, fact * (k + 1));
}

int main() {
    int n;
    
    printf("Введіть натуральне число n для Завдання 1: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Помилка: n має бути натуральним числом (n >= 1).
");
        return 1;
    }

    // Початкові значення для першого кроку: 
    // k=1, a1=1.0, b1=1.0, 1! = 1.0
    double sum1 = calc_sum1(1, n, 1.0, 1.0, 1.0);
    
    printf("Результат для завдання 1: %lf\n", sum1);

    return 0;
}

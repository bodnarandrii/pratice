#include <stdio.h>
#include <math.h>

double calc_sum1(int k, int n, double ak, double bk, double fact) {
    if (k > n) {
        return 0.0; 
    }
    
    double current_term = (ak * bk) / fact;
    
    double next_a = 0.5 * (sqrt(bk) + 0.5 * sqrt(ak));
    double next_b = 2.0 * ak * ak + bk;
    
    return current_term + calc_sum1(k + 1, n, next_a, next_b, fact * (k + 1));
}

int main() {
    int n;  
    
    printf("Input n (natural number): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: n must be a natural number (n >= 1).");
        return 1;
    }

    double sum1 = calc_sum1(1, n, 1.0, 1.0, 1.0);
    
    printf("Result: %lf\n", sum1);

    return 0;
}

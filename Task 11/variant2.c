#include <stdio.h>
#include <math.h>


double calc_sum2(int i, int n, double xi, double yi) {
    if (i > n) {
        return 0.0; 
    }
    
    double current_term = xi / (1.0 + fabs(yi));
    
    double next_x = 0.3 * xi;
    double next_y = xi * xi + yi;
    
    return current_term + calc_sum2(i + 1, n, next_x, next_y);
}

int main() {
    int n;
    
    printf("Input n(natural number): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: n must be a natural number (n >= 1). ");
        return 1;
    }

    double sum2 = calc_sum2(1, n, 1.0, 1.0);

    printf("Result: %lf\n", sum2);

    return 0;
}

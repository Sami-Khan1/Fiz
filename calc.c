#include <stdio.h>
#include <math.h>

// Derivative calculation tool
double derivative(double (*func)(double), double x, double h) {
    return (func(x + h) - func(x)) / h;
}

// Integration calculation tool
double definiteIntegral(double (*func)(double), double a, double b, int n) {
    double integ = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * integ;
        sum += func(x);
    }
    return integ * sum;
}

// Sample function (to change to user input in future or given context)
double sampleFunction(double x) {
    return x + 7;
}

int main() {
    double x = 2.0;  // derivative point to calc (user input in future)
    double h = 1e-5; // basically 0 for definition of derivative
    double a,b;
    int n = 25;
    printf("Enter the lower bound of integration: ");
    scanf("%lf", &a);
    printf("Enter the lower bound of integration: ");
    scanf("%lf", &b);

    double resultDev = derivative(sampleFunction, x, h);
    printf("The derivative at x = %f is approximately %.6f\n", x, resultDev);
    
    double resultInt = definiteIntegral(sampleFunction, a, b, n);
    printf("The definite integral from %.2f to %.2f is approximately %.6f\n", a, b, resultInt);

    return 0;
}
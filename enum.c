#include <stdio.h>
#include <string.h>

int fac(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int power(int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return 2 * power(exp - 1);
    }
}

enum cal { FAC, FIB, POWER, MAX };

int main() {
    int (*fp[MAX])(int) = {fac, fib, power};
    int n;
    char str[10];

    while (1) {
        printf("Enter the choice (fac for factorial, fib for Fibonacci, power for power of 2): ");
        scanf("%s", str);

        printf("Enter the value: ");
        scanf("%d", &n);

        if (strcmp(str, "fac") == 0) {
            printf("Factorial of %d is %d\n", n, fp[FAC](n));
        } else if (strcmp(str, "fib") == 0) {
            printf("Fibonacci of %d is %d\n", n, fp[FIB](n));
        } else if (strcmp(str, "power") == 0) {
            printf("2 raised to the power %d is %d\n", n, fp[POWER](n));
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


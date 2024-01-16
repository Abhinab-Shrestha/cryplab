#include <stdio.h>
#include<string.h>
int mod(int a, int m) {
    // Ensure that the result is non-negative
    return (a % m + m) % m;
}

int gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return d;
}

int findAdditiveInverse(int a, int m) {
    return mod(-a, m);
}

int findMultiplicativeInverse(int a, int m) {
    int x, y;
    int g = gcd(a, m, &x, &y);

    if (g != 1) {
        // Modular inverse doesn't exist
        return -1;
    }

    return mod(x, m);
}

int areRelativelyPrime(int a, int b) {
    return gcd(a, b, NULL, NULL) == 1;
}

int main() {
    int a, m;

    printf("Enter the values for a and m (space-separated): ");
    scanf("%d %d", &a, &m);
    getchar();
    printf("Additive Inverse of %d modulo %d: %d\n", a, m, findAdditiveInverse(a, m));

    int multiplicativeInverse = findMultiplicativeInverse(a, m);
    if (multiplicativeInverse != -1) {
        printf("Multiplicative Inverse of %d modulo %d: %d\n", a, m, multiplicativeInverse);getchar();
    } else {
        printf("Multiplicative Inverse does not exist for %d modulo %d\n", a, m);getchar();
    }

    printf("%d and %d are%s relatively prime.\n", a, m, areRelativelyPrime(a, m) ? "" : " not");
    getchar();
    return 0;
}

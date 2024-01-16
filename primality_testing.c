#include <stdio.h>

int q, k, random_int;

int getOdd();
void getParameters(int);
int checkPrimalityP1(int);
int checkPrimalityP2(int);
int modularExponentiation(int, int, int);

int main() {
    int n, p1_check, p2_check;
    int prime_status = 1; // to check whether any random integer is composite

    n = getOdd();
    getParameters(n);
    printf("\nq and k are %d, %d respectively\n", q, k);
    getchar();
    for (int j = 1; j < n; j++) {
        random_int = j;
        printf("\nRandom integer = %d\n", random_int);
    getchar();
        p1_check = checkPrimalityP1(n);

        if (p1_check == 1) {
            printf("Inconclusive\n");getchar();
        } else {
            p2_check = checkPrimalityP2(n);

            if (p2_check == 1) {
                printf("Inconclusive\n");getchar();
            } else {
                prime_status = 0;
                printf("Composite\n");getchar();
            }
        }
    }

    if (prime_status == 1) {
        printf("\nNumber %d is a Prime Number", n);
    } else {
        printf("\nNumber %d is not a Prime Number", n);
    }

    return 0;
}

int getOdd() {
    int odd;

    do {
        printf("\nEnter an Odd number greater than 2\n");
        scanf("%d", &odd);
        getchar();
    } while (odd % 2 == 0 || odd < 3);

    return odd;
}

void getParameters(int x) {
    int w, c = 0;

    w = x - 1;
    while ((w % 2) == 0) {
        w /= 2;
        c++;
    }

    q = w;
    k = c;
}

int modularExponentiation(int base, int exponent, int mod) {
    int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

int checkPrimalityP1(int odd) {
    return modularExponentiation(random_int, q, odd) == 1;
}

int checkPrimalityP2(int odd) {
    for (int j = 0; j < k; j++) {
        if (modularExponentiation(2, j, odd) == (odd - 1)) {
            return 1;
        }
    }

    return 0;
}

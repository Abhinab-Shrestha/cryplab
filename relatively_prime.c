#include <stdio.h>
#include<string.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int areRelativelyPrime(int x, int y) {
    return gcd(x, y) == 1;
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);
    getchar();
    // Check if the numbers are relatively prime
    if (areRelativelyPrime(num1, num2)) {
        printf("%d and %d are relatively prime.\n", num1, num2);getchar();
    } else {
        printf("%d and %d are not relatively prime.\n", num1, num2);getchar();
    }

    return 0;
}

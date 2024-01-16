#include<stdio.h>
#include<string.h>
int public_key_a, both_key_b; // Public key elements for Alice

long long int custom_power_long(long long int x, long long int y) {
    if (y == 0) {
        return 1;
    }

    long long int result = 1;
    for (long long int i = 1; i <= y; i++) {
        result *= x;
    }

    return result;
}

int generate_prime() {
    int prime, m;
    scanf("%d", &prime);
    m = prime - 1;

    while (m > 1) {
        if (prime % m == 0) {
            return generate_prime();
        }
        m--;
    }

    return prime;
}

int get_co_prime() {
    int x;
    printf("\nSelect an integer such that it is co-prime with the Euler toitent\n");
    scanf("%d", &x);
    getchar();
    return x;
}

int calculate_gcd(int p, int q) {
    while (q != 0) {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
}

int check_co_prime(int euler_toitent, int integer_val) {
    int gcd_val = calculate_gcd(euler_toitent, integer_val);
    printf("gcd %d", gcd_val);
    return gcd_val;
}

int multiplicative_inverse(int integer_val, int modulo) {
    int inverse_key = 1;
    for (int j = 1; j < modulo; j++) {
        if ((integer_val * j) % modulo == 1) {
            printf("\nMultiplicative Inverse of %d is %d\n", integer_val, j);
            inverse_key = j;
            break;
        }
    }
    
    return inverse_key;
}

int create_key_pair() {
    int p, q, n, euler_toitent_n, status_gcd = 0, e;
    printf("\nEnter first prime number\n");
    p = generate_prime();

    printf("\nEnter second prime number\n");
    q = generate_prime();

    n = p * q;
    euler_toitent_n = (p - 1) * (q - 1);

    printf("\nEuler Toitent is %d", euler_toitent_n);

    while (status_gcd == 0) {
        e = get_co_prime();
        status_gcd = check_co_prime(euler_toitent_n, e);
    }

    int d = multiplicative_inverse(e, euler_toitent_n);

    printf("\nPublic Key {%d,%d}\n", e, n);
    printf("\nPrivate Key {%d,%d}\n", d, n);

    public_key_a = e;
    both_key_b = n;

    return d;
}

int calculate_modular(int base_int, int full_pow, int modulo) {
    long long int temp_pow_res;
    long long int mod = 1, temp_mod_remainder;
    int partial_pow;

    while (full_pow > 0) {
        partial_pow = (full_pow / 5000) + 1;
        temp_pow_res = custom_power_long(base_int, partial_pow);
        temp_mod_remainder = temp_pow_res % modulo;
        mod = (mod * temp_mod_remainder) % modulo;
        full_pow = full_pow - partial_pow;
    }

    return (int)mod;
}

int get_plain_text() {
    int p;
    printf("\nEnter an integer plaintext\n");
    scanf("%d", &p);getchar();
    return p;
}

int encrypt_message() {
    int m = get_plain_text();
    if (m > both_key_b) {
        encrypt_message();
    }

    return calculate_modular(m, public_key_a, both_key_b);
}

int decrypt_message(int encrypted_txt, int alice_private) {
    return calculate_modular(encrypted_txt, alice_private, both_key_b);
}

int main() {
    int secret_key, encrypted_msg, decrypted_msg;

    secret_key = create_key_pair();

    encrypted_msg = encrypt_message();
    printf("\nEncrypting the message.....\n");
    printf("\nEncrypted Message %d\n", encrypted_msg);

    printf("\nDecrypting the message.....\n");
    decrypted_msg = decrypt_message(encrypted_msg, secret_key);
    printf("\nDecrypted Message %d\n", decrypted_msg);
    getchar();
    return 0;
}


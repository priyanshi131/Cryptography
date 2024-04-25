#include <iostream>
#include <cmath>

// Function to calculate power in modular arithmetic
long long int power(long long int a, long long int b, long long int P) {
    if (b == 1)
        return a;
    else
        return (long long int)(pow(a, b)) % P;
}

// Function to calculate secret key
long long int secretKey(long long int a, long long int x, long long int P) {
    return power(a, x, P);
}

int main() {
    long long int P, G, x, a, y, b, ka, kb;

    // Common prime number
    std::cout << "Enter a prime number (P): ";
    std::cin >> P;

    // Primitive root modulo of P
    std::cout << "Enter a primitive root modulo (G): ";
    std::cin >> G;

    // First person's private key
    std::cout << "Enter first person's private key (a): ";
    std::cin >> a;

    // Second person's private key
    std::cout << "Enter second person's private key (b): ";
    std::cin >> b;

    // Calculate public keys
    x = secretKey(G, a, P); // Public key for first person
    y = secretKey(G, b, P); // Public key for second person

    // Calculate secret keys
    ka = secretKey(y, a, P); // Secret key for first person
    kb = secretKey(x, b, P); // Secret key for second person

    std::cout << "First person's secret key (ka): " << ka << std::endl;
    std::cout << "Second person's secret key (kb): " << kb << std::endl;

    return 0;
}

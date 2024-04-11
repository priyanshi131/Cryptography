#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random key of the same length as the message
string generateKey(int length) {
    string key;
    for (int i = 0; i < length; ++i) {
        key += (rand() % 26) + 'A'; // Generating random uppercase letters for the key
    }
    return key;
}

// Function to perform One Time Pad encryption
string oneTimePadEncrypt(string message, string key) {
    string encrypted_message;
    for (size_t i = 0; i < message.length(); ++i) {
        char encrypted_char = ((message[i] - 'A') + (key[i] - 'A')) % 26 + 'A'; // Mod 26 operation for encryption
        encrypted_message += encrypted_char;
    }
    return encrypted_message;
}

// Function to perform One Time Pad decryption
string oneTimePadDecrypt(string encrypted_message, string key) {
    string decrypted_message;
    for (size_t i = 0; i < encrypted_message.length(); ++i) {
        char decrypted_char = ((encrypted_message[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A'; // Mod 26 operation for decryption
        decrypted_message += decrypted_char;
    }
    return decrypted_message;
}

int main() {
    srand(time(0)); // Seed the random number generator

    string message, key, encrypted_message, decrypted_message;

    cout << "Enter the message to encrypt (uppercase letters only): ";
    getline(cin, message);

    // Generating key of the same length as the message
    key = generateKey(message.length());

    encrypted_message = oneTimePadEncrypt(message, key);
    cout << "Encrypted message: " << encrypted_message << endl;
    cout << "Generated Key: " << key << endl;

    decrypted_message = oneTimePadDecrypt(encrypted_message, key);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}

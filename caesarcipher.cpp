#include <iostream>
#include <string>

using namespace std;

string caesarCipher(string message, int shift) {
    string encrypted_message = "";
    for (char& ch : message) {
        // Encrypt uppercase letters
        if (isupper(ch)) {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        encrypted_message += ch;
    }
    return encrypted_message;
}

int main() {
    string message;
    int shift;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the shift value (an integer): ";
    cin >> shift;

    string encrypted_message = caesarCipher(message, shift);
    cout << "Encrypted message: " << encrypted_message << endl;

    return 0;
}

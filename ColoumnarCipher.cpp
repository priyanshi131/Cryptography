#include <iostream>
#include <string>
#include <algorithm>

std::string removeSpaces(const std::string &str) {
    std::string result;
    for (char c : str) {
        if (!isspace(c)) {
            result.push_back(c);
        }
    }
    return result;
}

std::string encryptColumnarCipher(const std::string &message, const std::string &key) {
    std::string cleanMessage = removeSpaces(message);
    std::string cleanKey = removeSpaces(key);

    int numRows = cleanMessage.length() / cleanKey.length();
    if (cleanMessage.length() % cleanKey.length() != 0) {
        numRows++;
    }

    char matrix[numRows][cleanKey.length()];

    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < cleanKey.length(); j++) {
            if (index < cleanMessage.length()) {
                matrix[i][j] = cleanMessage[index++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    int keyIndex[cleanKey.length()];
    for (int i = 0; i < cleanKey.length(); i++) {
        keyIndex[i] = i;
    }

    std::sort(keyIndex, keyIndex + cleanKey.length(), [&](int a, int b) {
        return cleanKey[a] < cleanKey[b];
    });

    std::string encryptedMessage;
    for (int i = 0; i < cleanKey.length(); i++) {
        for (int j = 0; j < numRows; j++) {
            encryptedMessage.push_back(matrix[j][keyIndex[i]]);
        }
    }

    return encryptedMessage;
}

int main() {
    std::string message, key;
    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);
    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string encryptedMessage = encryptColumnarCipher(message, key);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    return 0;
}

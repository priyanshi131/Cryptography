#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function to convert a character to its numerical value (A=0, B=1, ..., Z=25)
int charToNum(char ch) {
    return ch - 'A';
}

// Function to convert a numerical value to its corresponding character (0=A, 1=B, ..., 25=Z)
char numToChar(int num) {
    return num + 'A';
}

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No modular inverse exists
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(vector<vector<int>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to calculate the inverse of a 2x2 matrix
void inverseMatrix(vector<vector<int>>& matrix, int mod) {
    int det = determinant(matrix);
    int detInverse = modInverse(det, mod);

    if (det == 0 || detInverse == -1) {
        cout << "Error: Matrix is not invertible." << endl;
        return;
    }

    int temp = matrix[0][0];
    matrix[0][0] = (matrix[1][1] * detInverse) % mod;
    matrix[1][1] = (temp * detInverse) % mod;
    matrix[0][1] = ((-1 * matrix[0][1]) * detInverse) % mod;
    matrix[1][0] = ((-1 * matrix[1][0]) * detInverse) % mod;

    // Ensure all elements are positive
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] += mod;
            }
        }
    }
}

// Function to perform Hill cipher encryption
string hillCipherEncrypt(string plaintext, vector<vector<int>>& keyMatrix, int mod) {
    string ciphertext = "";
    int n = keyMatrix.size();

    // Pad the plaintext if its length is not a multiple of n
    int padding = n - (plaintext.length() % n);
    if (padding != n) {
        plaintext += string(padding, 'X');
    }

    for (size_t i = 0; i < plaintext.length(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) {
            block[j] = charToNum(plaintext[i + j]);
        }

        vector<int> result(n, 0);
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                result[k] += keyMatrix[k][l] * block[l];
            }
            result[k] %= mod;
        }

        for (int k = 0; k < n; k++) {
            ciphertext += numToChar(result[k]);
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;
    vector<vector<int>> keyMatrix(2, vector<int>(2));
    int mod = 26;

    cout << "Enter the plaintext (uppercase letters only): ";
    getline(cin, plaintext);

    cout << "Enter the 2x2 key matrix (4 numbers separated by spaces): ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> keyMatrix[i][j];
        }
    }

    inverseMatrix(keyMatrix, mod);

    string ciphertext = hillCipherEncrypt(plaintext, keyMatrix, mod);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

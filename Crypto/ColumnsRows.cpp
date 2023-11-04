#include "Crypto.h"
#include <vector>
#include <iostream>
using namespace std;

class ColumnsRows : public Crypto {
    int key1 = 3;
public:
    void encrypt(string& text) override {
        int len = text.length();
        int rows;
        if (len % key1 == 0) {
            rows = len / key1;
        }
        else {
            rows = len / key1 + 1;
        }
        int cols = key1;

        vector<vector<char>> matrix(rows, vector<char>(cols));

        int index = 0;

        // Fill the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (index < len) {
                    matrix[i][j] = text[index];
                    cout << matrix[i][j] << "  ";
                    index++;
                }
            }
            cout << endl;
        }

        string encrypted;
        // Read the matrix column by column and print the encrypted text
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                encrypted += matrix[i][j];
            }
        }
        cout << encrypted << endl;
    }

    void decrypt(string& text) override {
        int len = text.length();
        int rows;
        int cols = key1;
        if (len % key1 == 0) {
            rows = len / key1;
        }
        else {
            rows = len / key1 + 1;
        }

        vector<vector<char>> matrix(rows, vector<char>(cols));

        int index = 0;

        // Fill the matrix column by column with characters from the encrypted text
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (index < len) {
                    matrix[i][j] = text[index];
                    cout << matrix[i][j] << "  ";
                    index++;
                }
                else{
                    matrix[i][j] = ' ';
                }
            }
            cout << endl;
        }

        string decryptedText;
        // Read the matrix row by row and print the decrypted text
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                decryptedText += matrix[i][j];
            }
        }

        cout << decryptedText;
    }
    void encryptDecrypt(string& text) {
        encrypt(text);
        decrypt(text);
    }
};
/*
int main() {
    string str;
    cout << "Input text to encrypt:\n";
    getline(cin, str);
    ColumnsRows object;
    object.encryptDecrypt(str);
    cout << endl;
}
*/

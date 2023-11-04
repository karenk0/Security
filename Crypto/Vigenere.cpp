#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class Vigenere : public Crypto {
public:
    virtual void encrypt(const std::string& text) override {
        if (text.empty()) {
            std::cout << "Input is empty! Can't encode.";
        }

        string key;
        cout << "Enter the key in uppercase: ";
        cin >> key;

        string encryptedMessage = text;
        int keyLength = key.length();

        for (int i = 0; i < text.length(); i++) {
            char messageChar = text[i];
            char keyChar = key[i % keyLength];
            //messageChar corresponding is keyChar

            if (isalpha(messageChar)) {
                // Encrypt the character
                encryptedMessage[i] = ( ((messageChar - 'A') + (keyChar - 'A')) % 26) + 'A';
            }
            else {
                encryptedMessage[i] = messageChar;
            }
        }
        cout << "\nEncrypted message: " << encryptedMessage;
    }

    virtual void decrypt(const std::string& encoded) override {
        if (encoded.empty()) {
            std::cout << "Input is empty! Can't decode.";
        }
        string decryptedMessage = encoded;

        string key;
        cout << "\nEnter the key in uppercase: ";
        cin >> key;

        int keyLength = key.length();

        for (int i = 0; i < encoded.length(); i++) {
            char encryptedChar = encoded[i];
            char keyChar = key[i % keyLength];

            if (isalpha(encryptedChar)) {
                decryptedMessage[i] = (encryptedChar -  keyChar + 26) % 26 + 'A';
            }
            else {
                decryptedMessage[i] = encryptedChar;
            }
        }
        cout << "Decrypted message: " << decryptedMessage;
    }
};

int main() {
    string message, key, encoded;

    cout << "Enter the message in uppercase: ";
    getline(cin, message);

    Vigenere object = Vigenere();
    object.encrypt(message);

    cout << "\nEnter the encoded message in uppercase: ";
    cin >> encoded;

    object.decrypt(encoded);
}


#include <iostream>
#include <string>
#include "Crypto.h"
using namespace std;

class VigenereGeneral : public Crypto {
public:
    virtual void encrypt(const std::string& text) override {

        if (text.empty()) {
            std::cout << "Input is empty! Can't encode.";
        }

        string key;
        cout << "Enter the key: ";
        cin >> key;

        string encryptedMessage = text;
        int keyLength = key.length();

        for (int i = 0; i < text.length(); ++i) {
            char keyChar = key[i % keyLength];
            encryptedMessage[i] = (text[i] + keyChar) % 256;
            cout << encryptedMessage[i];
        }
    }

    virtual void decrypt(const std::string& encoded) override {

        if (encoded.empty()) {
            std::cout << "Input is empty! Can't decode.";
        }

        string key;
        cout << "Enter the key: ";
        cin >> key;

        string decryptedText = encoded;
        int keyLength = key.length();

        for (int i = 0; i < encoded.length(); ++i) {
            char keyChar = key[i % keyLength];
            decryptedText[i] = (encoded[i] - keyChar + 256) % 256;
            cout << decryptedText[i];
        }
    }
};

int main() {
    string message, encoded;

    cout << "Enter the message: ";
    getline(cin, message);

    VigenereGeneral object = VigenereGeneral();
    object.encrypt(message);

    cout << "\nEnter the encoded message: ";
    cin >> encoded;

    object.decrypt(encoded);
}


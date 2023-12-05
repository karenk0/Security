#include <iostream>
#include <cctype>
#include <vector>
#include "Crypto.h"

class MyCrypto : public Crypto {
private:
    std::string key = "MCKJUDRXOFSLTGBNHIVPAEYWZ";
public:
    void encrypt(const std::string& text) override {
        int deviation;
        for (int i = 0; i < text.size(); i++) {
            deviation = std::toupper(text[i]) - 'A';
            //text[i] = key[deviation];
        }
    }

    void decrypt(const std::string& text) override { // const 
        for (int i = 0; i < text.size(); i++) {
            int j;
            for (j = 0; key[j] != text[i]; j++) {

            }  
            //text[i] = 'A' + j;
        }
    }
};


/*
int main()
{
    
    MyCrypto myCrypto;

    std::string original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //std::cout << "key:     " << myCrypto.key << std::endl;
    std::cout << "original:  " << original << std::endl << std::endl << std::endl;

    std::string originalText;
    std::cout << "Input Text" << std::endl;
    std::cin >> originalText;
    std::cout << "Original Text: " << originalText << std::endl;

    myCrypto.encrypt(originalText);
    std::string encryptedText = originalText;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    myCrypto.decrypt(encryptedText);
    std::string decryptedText = encryptedText;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;
    

}
*/



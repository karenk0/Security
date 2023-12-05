#include <iostream>
const int ROUNDS_COUNT = 99;

// Function to perform Feistel rounds
unsigned long long feistelRound(unsigned long left, unsigned long right, unsigned long roundKey) {
    unsigned long newLeft = right;
    unsigned long f = (right ^ roundKey);
    unsigned long newRight = left ^ f;
    return (static_cast<unsigned long long>(newLeft) << 32) | newRight;
}

unsigned long long encrypt(unsigned long long block, unsigned long key) {
    unsigned long right = static_cast<unsigned long>(block >> 32);
    unsigned long left = static_cast<unsigned long>(block);

    for (int round = 0; round < ROUNDS_COUNT; ++round) {
        unsigned  long roundKey = key >> round;
        block = feistelRound(left, right, roundKey);
        right = static_cast<unsigned long>(block >> 32);
        left = static_cast<unsigned long>(block);
    }

    // Final swap 
    return (static_cast<unsigned long long>(right) << 32) | left;
}

unsigned long long decrypt(unsigned long long block, unsigned long key) {
    return encrypt(block, key);   
}


int main() {
    unsigned long long originalText = 123456789LL;  // 64 bit 
    unsigned long encryptionKey = 789680897LL;  // 64 bit key

    std::cout << "Original text: " << originalText << std::endl;

    unsigned long long encryptedText = encrypt(originalText, encryptionKey);
    std::cout << "Encrypted: " << encryptedText << std::endl;

    unsigned long long decryptedText = decrypt(encryptedText, encryptionKey);
    std::cout << "Decrypted: " << decryptedText << std::endl;
}

#include <iostream>
#include <string>
#include "Crypto.h"

class RLE: public Crypto {
public:
    void encrypt(std::string& input) override{
        if (input.empty()) {
            std::cout << "Input is empty! Can't encode.";
        }

        std::string encoded;
        char current_char = input[0];
        int count = 1;

        for (size_t i = 1; i < input.size(); ++i) {
            if (input[i] == current_char) {
                count++;
            }
            else {
                encoded += current_char;
                encoded += "[" + std::to_string(count) + "]";
                current_char = input[i];
                count = 1;
            }
        }

        // Append the last character and its count.
        encoded += current_char;
        encoded += "[" + std::to_string(count) + "]";

        std::cout << "Encoded input:    " << encoded << std::endl;
    }

    // Decode the RLE-encoded string back to the original form.
    void decrypt(std::string& encoded) override {
        if (encoded.empty()) {
            std::cout << "Input is empty! Can't decode.";
        }

        std::string decoded;
        size_t i = 0;

        while (i < encoded.size()) {
            char current_char = encoded[i];
            ++i;
            int count = 0;

            if (i < encoded.size() && encoded[i] == '[') {
                ++i;
                while (i < encoded.size() && isdigit(encoded[i]) && encoded[i] != ']') {
                    count = count * 10 + (encoded[i] - '0');
                    ++i;
                }
                if (i < encoded.size() && encoded[i] == ']') {
                    ++i;
                }
            }

            // Append the character 'count' times to the decoded string.
            decoded += std::string(count, current_char);
        }
        std::cout << "Decoded input:    " << decoded;
    }
};

/*
int main() {
    std::string original = "3333ABBBBB";
    RLE object_rle;

    std::cout << "Original: " << original << std::endl;
    object_rle.encrypt(original);

    std::string decoded = "A[3]B[3]C[3]D[4]5[4]";
    object_rle.decrypt(decoded);
}
*/
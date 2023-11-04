#include <iostream>
#include <string>
#include "Crypto.h"
#include <vector>

class RLE2 : public Crypto {
public:
    void encrypt(std::string& text) override {
        if (text.empty()) {
            std::cout << "Input is empty! Can't encode.";
        }

        std::string encoded = "";
        char current_char = text[0];
        int count = 1;
        bool more_than_2 = true;

        for (size_t i = 1; i < text.size(); ++i) {
            if (text[i] == current_char && count <= 127) {
                count++;
            }
            else {
                encoded = encoded + "[" + ( more_than_2 == false ? "1|" : "0|") + std::to_string(count) + "]";
                encoded += current_char;
                current_char = text[i];
                count = 1;
                more_than_2 = true;
            }
            if (count >= 2 && more_than_2 == true) {
                count -= 2; //1:  this enables to code up to 129 length, cause 0, 1 is not used
                more_than_2 = false;
            }
        }

        encoded = encoded + "[" + (count >= 2 ? "1|" : "0|") + std::to_string(count) + "]";
        encoded += current_char;
        std::cout << "Encoded input:    " << encoded << std::endl;
    }
    
    void decrypt(std::string& encoded) override {
        if (encoded.empty()) {
            std::cout << "Input is empty! Can't decode.";
        }

        std::string decoded;
        size_t i = 0;
        int count;

        while (i < encoded.size()) {        
            count = 0;

            if (i < encoded.size() && encoded[i] == '[') {
                ++i;
                if (encoded[i] == '1') {
                    i += 2;
                    while (i < encoded.size() && isdigit(encoded[i]) && encoded[i] != ']') {
                        
                        count = count * 10 + (encoded[i] - '0' - 2);
                        
                        ++i;
                    }
                    count += 2; //1:
                    if (i < encoded.size() && encoded[i] == ']') {
                        ++i;
                    }
                }
                else {
                    i += 2;
                    count = encoded[i] - '0';
                    i += 2;
                }
            }
            // Append the character 'count' times to the decoded string.
            decoded += std::string(count, encoded[i]);
            i++;
        }
        std::cout << "Decoded input:    " << decoded;
    }
};

/*
int main() {
    std::string original = "3333ABBBBB6667";
    RLE2 object_rle;

    std::cout << "Original: " << original << std::endl;
    object_rle.encrypt(original);

    std::string decoded = "[1|4]3[0|1]A[1|5]B[1|3]6[0|1]7";
    object_rle.decrypt(decoded);
}
*/

/*

#include <iostream>
#include <string>
#include "Crypto.h"
#include <vector>

class RLE2 : public Crypto {
public:
    void encrypt(std::string& text) override {
        if (text.empty()) {
            std::cout << "Input is empty! Can't encode.";
        }

        std::string encoded = "";
        char current_char = text[0];
        int count = 1;

        for (size_t i = 1; i < text.size(); ++i) {
            if (text[i] == current_char && count <= 127) {
                count++;
            }
            else {
                encoded = encoded + "[" + ( count >= 2 ? "1|" : "0|") + std::to_string(count) + "]";
                encoded += current_char;
                current_char = text[i];
                count = 1;
            }
        }

        encoded = encoded + "[" + (count >= 2 ? "1|" : "0|") + std::to_string(count) + "]";
        encoded += current_char;
        std::cout << "Encoded input:    " << encoded << std::endl;
    }

    void decrypt(std::string& encoded) override {
        if (encoded.empty()) {
            std::cout << "Input is empty! Can't decode.";
        }

        std::string decoded;
        size_t i = 0;
        int count;

        while (i < encoded.size()) {
            count = 0;

            if (i < encoded.size() && encoded[i] == '[') {
                ++i;
                if (encoded[i] == '1') {
                    i += 2;
                    while (i < encoded.size() && isdigit(encoded[i]) && encoded[i] != ']') {
                        count = count * 10 + (encoded[i] - '0');
                        ++i;
                    }
                    if (i < encoded.size() && encoded[i] == ']') {
                        ++i;
                    }
                }
                else {
                    i += 2;
                    count = encoded[i] - '0';
                    i += 2;
                }
            }
            // Append the character 'count' times to the decoded string.
            decoded += std::string(count, encoded[i]);
            i++;
        }
        std::cout << "Decoded input:    " << decoded;
    }
};

int main() {
    std::string original = "3333ABBBBB6667";
    RLE2 object_rle;

    std::cout << "Original: " << original << std::endl;
    object_rle.encrypt(original);

    std::string decoded = "[1|4]3[0|1]A[1|5]B[1|3]6[0|1]7";
    object_rle.decrypt(decoded);
}
*/
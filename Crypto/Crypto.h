#pragma once
#include <string>

class Crypto {
public:
    virtual void encrypt(const std::string& text) = 0;
    virtual void decrypt(const std::string& text) = 0;
};

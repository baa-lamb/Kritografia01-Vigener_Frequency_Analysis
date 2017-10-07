#ifndef KRIPTOGRAFIA01_VIGENERDECRYPT_H
#define KRIPTOGRAFIA01_VIGENERDECRYPT_H

#include <iostream>
#include <fstream>
#include <string>

class VigenerDecipher {
public:
    VigenerDecipher(std::string pathIn, std::string pathOut, std::string key);

    ~VigenerDecipher();

    void decipherFile();

private:
    std::ifstream finEncrypt_;
    std::ofstream foutDecipher_;
    std::string key_;
};

#endif //KRIPTOGRAFIA01_VIGENERDECRYPT_H

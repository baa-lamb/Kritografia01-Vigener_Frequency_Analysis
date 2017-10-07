#ifndef KRIPTOGRAFIA01_VIGENERENCRYPT_H
#define KRIPTOGRAFIA01_VIGENERENCRYPT_H

#include <iostream>
#include <fstream>
#include <string>

class VigenerEncrypt {
public:
    VigenerEncrypt(std::string pathIn, std::string pathOut, std::string key);

    ~VigenerEncrypt();

    void encryptFile();

private:
    std::ifstream fin_;
    std::ofstream foutEncrypt_;
    std::string key_;
};

#endif //KRIPTOGRAFIA01_VIGENERENCRYPT_H

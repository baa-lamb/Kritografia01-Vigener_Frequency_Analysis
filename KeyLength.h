#ifndef KRIPTOGRAFIA01_KEYLENGTH_H
#define KRIPTOGRAFIA01_KEYLENGTH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class KeyLength {
public:
    KeyLength(std::string pathIn, int maxKeySize);

    ~KeyLength();

    double findMatchIndex(int mod);

    int getKeySize();

private:
    std::ifstream finEncrypt_;
    int keySize_;
    int maxKeySize_;
};


#endif //KRIPTOGRAFIA01_KEYLENGTH_H

#include "VigenerDecipher.h"

VigenerDecipher::VigenerDecipher(std::string pathIn, std::string pathOut, std::string key) {
    finEncrypt_.open(pathIn);
    foutDecipher_.open(pathOut);
    key_ = key;
}

VigenerDecipher::~VigenerDecipher() {
    finEncrypt_.close();
    foutDecipher_.close();
}

void VigenerDecipher::decipherFile() {
    if (!foutDecipher_.is_open())
        std::cout << "error opening the 'outputDecipher'" << std::endl;
    else if (!finEncrypt_.is_open())
        std::cout << "error opening the 'outputEncrypt'" << std::endl;
    else {
        int keySize = key_.size();
        int count = 0;
        int symbol;
        while ((symbol = finEncrypt_.get()) != EOF) {
            int numberInAlphabet = (symbol - (int) key_[count % keySize] - 32) % 223;
            while (numberInAlphabet < 0)
                numberInAlphabet += 223;
            foutDecipher_ << (char) numberInAlphabet;
            count++;
        }
    }
}
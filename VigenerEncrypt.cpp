#include "VigenerEncrypt.h"

VigenerEncrypt::VigenerEncrypt(std::string pathIn, std::string pathOut, std::string key) {
    fin_.open(pathIn);
    foutEncrypt_.open(pathOut);
    key_ = key;
}

VigenerEncrypt::~VigenerEncrypt() {
    fin_.close();
    foutEncrypt_.close();
}

void VigenerEncrypt::encryptFile() {
    if (!fin_.is_open())
        std::cout << "error opening the input.txt" << std::endl;
    else if (!foutEncrypt_.is_open())
        std::cout << "error opening the outputEncrypt.txt" << std::endl;
    else {
        int keySize = key_.size();
        int count = 0;
        int symbol;
        while ((symbol = fin_.get()) != EOF) {
            int numberInAlphabet = ((symbol + (int) key_[count % keySize]) % 223) + 32;
            foutEncrypt_ << (char) numberInAlphabet;
            count++;
        }
    }
    foutEncrypt_.close();
}

#include "VigenerEncrypt.h"
#include "VigenerDecipher.h"
#include "KeyLength.h"
#include "VigenerFrequencyAnalysis.h"

std::string generateKey(int maxKeySize) {
    srand(time(0));
    std::string key = "";
    int sizeKey = 1 + rand() % maxKeySize;
    for (int i = 0; i < sizeKey; i++) {
        char symbol = (char) (32 + rand() % maxKeySize);
        key += symbol;
    }
    return key;
}

int main() {
    int maxKeySize = 70; //максимальный размер ключа
    std::cout << "Input your KEY (if you don't want to choose key input 'random'): ";
    std::string key;
    std::cin >> key;
    if (key == "random")
        key = generateKey(maxKeySize);
    std::cout << std::endl << "Your key is: " << key << " \nYour key size: " << key.size() << std::endl;

    std::string pathInput = "files/input.txt", pathEncrypt = "files/outputEncrypt.txt",
            pathDecipher = "files/outputDecrypt.txt", pathOutput = "files/output.txt",
            pathExample = "files/example.txt";

    VigenerEncrypt encrypt(pathInput, pathEncrypt, key);
    encrypt.encryptFile();

    VigenerDecipher decipher(pathEncrypt, pathDecipher, key);
    decipher.decipherFile();

    KeyLength keyLength(pathEncrypt, maxKeySize);
    int keySize = keyLength.getKeySize();
    std::cout << "YOUR KEY SIZE: " << keySize << std::endl;

    VigenerFrequencyAnalysis analis(pathEncrypt, pathOutput, pathExample, keySize);
    key = analis.decipherByAnalisis();
    std::cout << "YOUR KEY IS: " << key << std::endl;

    VigenerDecipher decipher1(pathEncrypt, pathOutput, key);
    decipher1.decipherFile();

    return 0;
}
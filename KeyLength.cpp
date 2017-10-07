#include "KeyLength.h"

KeyLength::KeyLength(std::string pathIn, int maxKeySize) {
    finEncrypt_.open(pathIn);
    maxKeySize_ = maxKeySize;
}

KeyLength::~KeyLength() {
    finEncrypt_.close();
}

double KeyLength::findMatchIndex(int mod) {
    finEncrypt_.clear();
    finEncrypt_.seekg(0, std::ios::beg);

    std::map<char, double> statistic;

    int count = -1, countNewText = 0;
    int symbol;
    while ((symbol = finEncrypt_.get()) != EOF) {
        count++;
        if (count % mod != 0)
            continue;
        if (statistic.find(symbol) == statistic.end())
            statistic.insert(std::pair<char, double>((char) symbol, 1.000));
        else
            statistic[symbol]++;
        countNewText++;
    }
    double index = 0.000;
    for (auto it = statistic.begin(); it != statistic.end(); it++) {
        index += ((it->second) * (it->second - 1.000)) / ((double) countNewText * ((double) countNewText - 1.000));
    }
    return index;
}

int KeyLength::getKeySize() {
    finEncrypt_.clear();
    finEncrypt_.seekg(0, std::ios::beg);

    keySize_ = 1;
    double index = 0.000, max = 0.0001;
    for (int i = 1; i <= maxKeySize_; i++) {
        index = findMatchIndex(i);
        if (index > 0.05500 && index < 0.08000) {
            max = index;
            keySize_ = i;
            break;
        }
    }
    return keySize_;
}


/// Теория
// Индекс совпадений — число, характеризующее вероятность того,
// что две произвольно выбранные из текста буквы окажутся одинаковыми. Вычисляется по формуле ..., где
// fi — количество появлений i-й буквы алфавита в тексте, а n — количество букв в тексте.
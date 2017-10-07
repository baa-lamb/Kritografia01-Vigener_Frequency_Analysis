#include "VigenerFrequencyAnalysis.h"

VigenerFrequencyAnalysis::VigenerFrequencyAnalysis(std::string pathIn, std::string pathOut,
                                                   std::string pathExample, int keySize) {
    finEncrypt_.open(pathIn);
    finExample_.open(pathExample);
    foutOutput_.open(pathOut);
    keySize_ = keySize;
}

VigenerFrequencyAnalysis::~VigenerFrequencyAnalysis() {
    finExample_.close();
    finEncrypt_.close();
    foutOutput_.close();
}

int VigenerFrequencyAnalysis::getMax(std::map<unsigned char, double> statistic) {
    double max = -1.000;
    int symbol = 0;
    for (auto it = statistic.begin(); it != statistic.end(); it++) {
        if (max < it->second) {
            max = it->second;
            symbol = it->first;
        }
    }
    return symbol;
}

std::map<unsigned char, double> VigenerFrequencyAnalysis::getStatistics(std::ifstream &file, int start, int step) {
    file.clear();
    file.seekg(0, std::ios::beg);
    std::map<unsigned char, double> statistics;
    int symbol = 0;
    int count = -1;
    while ((symbol = file.get()) != EOF) {
        count++;
        if (count != start)
            continue;
        start += step;
        if (statistics.find(symbol) == statistics.end())
            statistics.insert(std::pair<unsigned char, double>(symbol, 1.000));
        else
            statistics[symbol]++;
    }
    for (auto it = statistics.begin(); it != statistics.end(); ++it)
        it->second = ((it->second * 100.000) / (double) count);

    return statistics;
}

std::string VigenerFrequencyAnalysis::decipherByAnalisis() {
    if (!finExample_.is_open())
        std::cout << "example file can't open" << std::endl;
    else {
        std::map<unsigned char, double> statisticExample = getStatistics(finExample_, 0, 1);
        int maxSymbolExamle = getMax(statisticExample);

        std::string key = "";
        for (int i = 0; i < keySize_; i++) {
            std::map<unsigned char, double> statisticEncrypt = getStatistics(finEncrypt_, i, keySize_);
            int maxSymbolEncrypt = getMax(statisticEncrypt);
            int newSymbolInKey = (maxSymbolEncrypt - maxSymbolExamle - 32) % 223;
            while(newSymbolInKey < 0)
                newSymbolInKey += 223;
            key += (char) newSymbolInKey;
        }
        return key;
    }
}
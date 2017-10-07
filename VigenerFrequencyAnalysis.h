#ifndef KRIPTOGRAFIA01_FREQUENCYANALYSIS_H
#define KRIPTOGRAFIA01_FREQUENCYANALYSIS_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


class VigenerFrequencyAnalysis {
public:
    VigenerFrequencyAnalysis(std::string pathIn, std::string pathOut, std::string pathExample, int keySize);

    ~VigenerFrequencyAnalysis();

    int getMax(std::map<unsigned char, double> statistic);

    std::map<unsigned char, double> getStatistics(std::ifstream &fin, int start, int step);

    std::string decipherByAnalisis();

private:
    std::ifstream finEncrypt_;
    std::ifstream finExample_;
    std::ofstream foutOutput_;
    int keySize_;
};

#endif //KRIPTOGRAFIA01_FREQUENCYANALYSIS_H

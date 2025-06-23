#pragma once
#include <unordered_map>
#include <fstream>
using namespace std;

class FrequencyCounter {
    unordered_map<char, int> freqMap;
public:
    void readFile(const string& filePath);
    const unordered_map<char, int>& getFrequencyMap() const;
};

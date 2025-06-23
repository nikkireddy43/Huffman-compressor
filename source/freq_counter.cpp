#include "freq_counter.h"

void FrequencyCounter::readFile(const string& filePath) {
    ifstream in(filePath, ios::in);
    char ch;
    while (in.get(ch))
        freqMap[ch]++;
    in.close();
}

const unordered_map<char, int>& FrequencyCounter::getFrequencyMap() const {
    return freqMap;
}
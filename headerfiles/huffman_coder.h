#pragma once

#include <string>              
#include <unordered_map>       

#include "node.h"               

class HuffmanCoder {
    std::unordered_map<char, std::string> codeMap;
    Node* buildTreeFromMap();
    void buildCode(Node* root, std::string code);
public:
    void buildFromFrequency(const std::unordered_map<char, int>& freqMap);
    void compressToFile(const std::string& inputPath, const std::string& outputPath);
    void decompressToFile(const std::string& binPath, const std::string& outPath);
    void saveCodeMap(const std::string& mapPath);
    void loadCodeMap(const std::string& mapPath);
};

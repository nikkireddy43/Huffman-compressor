#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

class HuffmanUtil {
public:
    static void saveMap(const unordered_map<char, string>& map, const string& path);
    static unordered_map<char, string> loadMap(const string& path);
};
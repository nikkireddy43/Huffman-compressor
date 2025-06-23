#include "huffman_util.h"

void HuffmanUtil::saveMap(const unordered_map<char, string>& map, const string& path) {
    ofstream out(path);
    for (auto it = map.begin(); it != map.end(); ++it) {
        char ch = it->first;
        string code = it->second;
        out << int((unsigned char)ch) << ' ' << code << '\n';
    }
    out.close();
}

unordered_map<char, string> HuffmanUtil::loadMap(const string& path) {
    unordered_map<char, string> map;
    ifstream in(path);
    int ascii;
    string code;
    while (in >> ascii >> code)
        map[char(ascii)] = code;
    return map;
}

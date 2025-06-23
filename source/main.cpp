#include <iostream>
#include "freq_counter.h"
#include "huffman_coder.h"
using namespace std;

int main() {
    HuffmanCoder huffman;
    string mode;

    cout << "Enter option (1 = compress, 2 = decompress): ";
    cin >> mode;

    if (mode == "1") {
        string inputPath, mapPath, binPath;
        cout << "Enter input file path to compress: ";
        cin.ignore();
        getline(cin, inputPath);
        cout << "Enter path to save map file: ";
        getline(cin, mapPath);
        cout << "Enter path to save compressed binary file: ";
        getline(cin, binPath);

        FrequencyCounter fc;
        fc.readFile(inputPath);
        huffman.buildFromFrequency(fc.getFrequencyMap());
        huffman.saveCodeMap(mapPath);
        huffman.compressToFile(inputPath, binPath);
        cout << "Compression successful!\n";

    } else if (mode == "2") {
        string mapPath, binPath, outPath;
        cout << "Enter map file path: ";
        cin.ignore();
        getline(cin, mapPath);
        cout << "Enter binary file path to decompress: ";
        getline(cin, binPath);
        cout << "Enter output file path: ";
        getline(cin, outPath);

        huffman.loadCodeMap(mapPath);
        huffman.decompressToFile(binPath, outPath);
        cout << "Decompression successful!\n";
    } else {
        cout << "Invalid option.\n";
    }

    return 0;
}

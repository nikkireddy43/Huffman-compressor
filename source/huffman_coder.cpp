#include "huffman_coder.h"
#include "huffman_util.h"
#include <bitset>
#include <fstream>
#include <queue>

#define INTERNAL_NODE char(128)
#define PSEUDO_EOF char(129)

using namespace std;

class Comp {
public:
    bool operator()(Node* a, Node* b) {
        return a->getFrequency() > b->getFrequency();
    }
};

void HuffmanCoder::buildFromFrequency(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Comp> pq;
    for (unordered_map<char, int>::const_iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
        char ch = it->first;
        int freq = it->second;
        pq.push(new Node(ch, freq));
    }
    pq.push(new Node(PSEUDO_EOF, 1));

    while (pq.size() > 1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node *merged = new Node(INTERNAL_NODE, l->getFrequency() + r->getFrequency());
        merged->setLeft(l); merged->setRight(r);
        pq.push(merged);
    }

    buildCode(pq.top(), "");
}

void HuffmanCoder::buildCode(Node* root, string code) {
    if (!root) return;
    if (root->getChar() != INTERNAL_NODE)
        codeMap[root->getChar()] = code;
    buildCode(root->getLeft(), code + "0");
    buildCode(root->getRight(), code + "1");
}

void HuffmanCoder::compressToFile(const string& inputPath, const string& outputPath) {
    ifstream in(inputPath);
    ofstream out(outputPath, ios::binary);
    string encoded;
    char ch;
    while (in.get(ch))
        encoded += codeMap[ch];
    encoded += codeMap[PSEUDO_EOF];
    while (encoded.size() % 8) encoded += '0';

    for (size_t i = 0; i < encoded.size(); i += 8) {
        bitset<8> bits(encoded.substr(i, 8));
        out.put((char)bits.to_ulong());
    }
    in.close(); out.close();
}

void HuffmanCoder::decompressToFile(const string& binPath, const string& outPath) {
    ifstream in(binPath, ios::binary);
    ofstream out(outPath);
    string bits;
    char ch;
    while (in.get(ch))
        bits += bitset<8>(ch).to_string();

    Node* root = buildTreeFromMap();
    Node* node = root;
    for (size_t i = 0; i < bits.size(); ++i) {
        char bit = bits[i];
        node = (bit == '0') ? node->getLeft() : node->getRight();
        if (node->getChar() != INTERNAL_NODE) {
            if (node->getChar() == PSEUDO_EOF) break;
            out.put(node->getChar());
            node = root;
        }
    }
    in.close(); out.close();
}

void HuffmanCoder::saveCodeMap(const string& mapPath) {
    HuffmanUtil::saveMap(codeMap, mapPath);
}

void HuffmanCoder::loadCodeMap(const string& mapPath) {
    codeMap = HuffmanUtil::loadMap(mapPath);
}

Node* HuffmanCoder::buildTreeFromMap() {
    Node* root = new Node(INTERNAL_NODE);
    for (unordered_map<char, string>::iterator it = codeMap.begin(); it != codeMap.end(); ++it) {
        char ch = it->first;
        string code = it->second;
        Node* cur = root;
        for (size_t i = 0; i < code.size(); ++i) {
            if (code[i] == '0') {
                if (!cur->getLeft()) cur->setLeft(new Node(INTERNAL_NODE));
                if (i == code.size() - 1) cur->setLeft(new Node(ch));
                cur = cur->getLeft();
            } else {
                if (!cur->getRight()) cur->setRight(new Node(INTERNAL_NODE));
                if (i == code.size() - 1) cur->setRight(new Node(ch));
                cur = cur->getRight();
            }
        }
    }
    return root;
}

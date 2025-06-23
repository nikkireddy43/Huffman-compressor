#pragma once

class Node {
    char ch;
    int freq;
    Node *left, *right;
public:
    Node(char c, int f);
    Node(char c);
    int getFrequency() const;
    char getChar() const;
    Node* getLeft() const;
    Node* getRight() const;
    void setLeft(Node* l);
    void setRight(Node* r);
};
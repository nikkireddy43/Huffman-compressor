#include "node.h"

Node::Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
Node::Node(char c) : ch(c), freq(0), left(nullptr), right(nullptr) {}
int Node::getFrequency() const { return freq; }
char Node::getChar() const { return ch; }
Node* Node::getLeft() const { return left; }
Node* Node::getRight() const { return right; }
void Node::setLeft(Node* l) { left = l; }
void Node::setRight(Node* r) { right = r; }
#include <iostream>
#include <string>

class Node {
public:
  bool mFlag;
  Node *mChildren[26];
  Node() : mFlag{false} {}
  Node(bool flag) : mFlag{flag} {}

  bool containsKey(char ch) {
    int idx = int(ch) - (int)'a';
    return mChildren[idx] != nullptr;
  }

  void put(char ch, Node *node) {

    int idx = int(ch) - (int)'a';
    mChildren[idx] = node;
  }

  Node *get(char ch) {

    int idx = int(ch) - (int)'a';
    return mChildren[idx];
  }

  void setEnd() { mFlag = true; }

  bool isEnd() { return mFlag; }
};

class Trie {
  Node *root;

public:
  void insert(std::string word) {

    Node *node = root;
    for (char &ch : word) {
      if (!node->containsKey(ch)) {
        node->put(ch, new Node);
      }
      node = node->get(ch);
    }
    node->setEnd();
  }

  bool search(std::string word) {
    Node *node = root;
    for (char &ch : word) {
      if (node->containsKey(ch)) {
        node = node->get(ch);
      } else {
        return false;
      }
    }
    return node->isEnd();
  }

  bool startsWith(std::string word) {
    Node *node = root;
    for (char &ch : word) {
      if (node->containsKey(ch)) {
        node = node->get(ch);
      } else {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {


  return 0;
}

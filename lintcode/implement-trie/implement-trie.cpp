#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
    friend class Trie;
private:
    char val;
    map<char, TrieNode*> children;
public:

    // Initialize your data structure here.
    TrieNode() {
        this->val = '^';
    }

    TrieNode(char _val) {
        this->val = _val;
    }
};

class Trie {
private:
    TrieNode *root;

    bool search_(string word) {
        TrieNode *current = root;

        for (char &c : word) {
            auto it = current->children.find(c);

            if (it != current->children.end()) {
                current = (*it).second;
            } else {
                return false;
            }
        }

        return true;
    }
public:
    Trie() {
        root = new TrieNode('^');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        word = word + "$";

        TrieNode *current = root;
        for(char &c : word) {
            auto it = current->children.find(c);

            if (it != current->children.end()) {
                current = (*it).second;
            } else {
                TrieNode *node = new TrieNode(c);

                current->children[c] = node;
                current = node;
            }
        }
    }

    void print(TrieNode *node, int depth) {
        cout << node->val;
        cout << endl;
        if (node->children.size() == 0) return;

        for (auto &pair : node->children) {
            for (int i=0; i<=depth; i++) cout << '-';
            cout << ">";
            print(pair.second, depth+1);
        }
    }

    void print() {
        print(this->root, 0);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return this->search_(word + "$");
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return this->search_(prefix);
    }
};

int main() {
    Trie trie;
    trie.insert("lintcode");
    trie.insert("linter");
    trie.print();
    cout << "search 'lint': " << trie.search("lint") << endl;
    cout << "search 'linter': " << trie.search("linter") << endl;
    cout << "startsWith 'lint': " << trie.startsWith("lint") << endl;
}

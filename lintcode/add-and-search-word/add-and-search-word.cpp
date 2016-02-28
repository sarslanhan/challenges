#include <iostream>
#include <map>
#include <string>

using namespace std;

class TrieNode {
    friend class WordDictionary;
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

class WordDictionary {
    private:
    TrieNode *root;

    bool search_(string &word) {
        return this->search_(root, word, 0l);
    }

    bool search_(TrieNode *node, string &word, unsigned long index) {
        if (index >= word.size()) return false;

        if (index == word.size()-1 && (word[index] == '.' || node->val == word[index])) return true;

        cout << "searching for " << word[index] << " in " << word << " on " << node->val << " with index " << index << endl;

        if ((node->val == word[index] || word[index] == '.') && index < word.size()-1) {
            char next = word[index+1];

            cout << "searching for the next char: " << next << endl;

            if (next == '.') {
                for (auto &pair : node->children) {
                    bool result = search_(pair.second, word, index+1);

                    if (result) return true;
                }
            } else {
                auto it = node->children.find(next);

                if (it != node->children.end()) {
                    cout << "found child on " << (*it).first << endl;
                    return search_((*it).second, word, index+1);
                } else {
                    return false;
                }
            }
        }

        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode('^');
    }

    // Inserts a word into the trie.
    void addWord(string word) {
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
        word = "^" + word + "$";

        return this->search_(word);
    }
};

int main() {
    WordDictionary wd;

    wd.addWord("a");
    wd.addWord("a");
    wd.print();
    cout << wd.search(".") << endl;
    cout << wd.search("a") << endl;
    cout << wd.search("aa") << endl;
    cout << wd.search("a") << endl;
    cout << wd.search(".a") << endl;
    cout << wd.search("a.") << endl;
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

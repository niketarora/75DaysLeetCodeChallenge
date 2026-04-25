#include <string>
#include <vector>

using namespace std;

class WordDictionary {
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    // Helper function for recursive wildcard search
    bool searchInNode(const string& word, int index, TrieNode* node) {
        if (node == nullptr) return false;
        if (index == word.length()) return node->isEndOfWord;

        char c = word[index];
        if (c == '.') {
            // Wildcard: try all 26 possible branches
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchInNode(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            // Standard character: follow specific branch
            return searchInNode(word, index + 1, node->children[c - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
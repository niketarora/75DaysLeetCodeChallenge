struct TrieNode {
    TrieNode* children[26] = {};
    string* word = nullptr; // Stores the word at the end node to identify matches
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!curr->children[idx]) curr->children[idx] = new TrieNode();
                curr = curr->children[idx];
            }
            curr->word = &w; // Store pointer to word to avoid duplicates later
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        // If current character is not in Trie, stop exploring
        if (ch == '#' || !node->children[idx]) return;
        
        node = node->children[idx];
        if (node->word) {
            result.push_back(*node->word);
            node->word = nullptr; // Mark as found to avoid duplicate results
        }

        // Backtracking: mark current cell as visited
        board[r][c] = '#';
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }
        
        // Backtrack: restore original character
        board[r][c] = ch;
    }
};

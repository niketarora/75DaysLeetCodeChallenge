#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // A single set to store seen constraints (number + position/type)
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char number = board[i][j];
                
                // Skip empty cells
                if (number == '.') continue;

                // Create unique string identifiers for rows, cols, and boxes
                string rowKey = string(1, number) + " in row " + to_string(i);
                string colKey = string(1, number) + " in col " + to_string(j);
                // 3x3 box index is calculated as (row/3) * 3 + (col/3)
                string boxKey = string(1, number) + " in box " + to_string(i/3) + "-" + to_string(j/3);

                // If any of these insertions fail, the number already exists
                if (!seen.insert(rowKey).second ||
                    !seen.insert(colKey).second ||
                    !seen.insert(boxKey).second) {
                    return false;
                }
            }
        }
        return true;
    }
};

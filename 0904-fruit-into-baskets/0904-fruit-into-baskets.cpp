#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int max_fruits = 0;
        int left = 0;
        
        // r is the right pointer of the sliding window
        for (int r = 0; r < fruits.size(); ++r) {
            count[fruits[r]]++;
            
            // If we have more than 2 types, shrink window from left
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }
            
            // Update the maximum window size
            max_fruits = max(max_fruits, r - left + 1);
        }
        
        return max_fruits;
    }
};

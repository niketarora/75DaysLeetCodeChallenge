#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Initialize a max-heap with the stones
        std::priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        // Smash stones until 0 or 1 stone remains
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); // Heaviest stone
            maxHeap.pop();
            int stone2 = maxHeap.top(); // Second heaviest stone
            maxHeap.pop();
            
            // If they are not equal, push the remainder back
            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }
        
        // Return the weight of the last stone, or 0 if none remain
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

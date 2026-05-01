#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store frequency of prefix sums encountered so far
        unordered_map<int, int> prefixSumFreq;
        
        // Base case: a prefix sum of 0 has occurred once (for subarrays starting from index 0)
        prefixSumFreq[0] = 1;
        
        int currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currentSum += num; // Update running prefix sum
            
            // If (currentSum - k) exists in the map, it means there is a subarray
            // ending at the current index with a sum equal to k.
            if (prefixSumFreq.find(currentSum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[currentSum - k];
            }
            
            // Record the current prefix sum in the map
            prefixSumFreq[currentSum]++;
        }
        
        return count;
    }
};

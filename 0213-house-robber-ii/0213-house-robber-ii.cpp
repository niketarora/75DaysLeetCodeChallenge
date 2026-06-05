#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases: No houses or exactly one house
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Return the max of skipping the last house vs skipping the first house
        return std::max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    // Helper function to solve the standard linear House Robber problem
    int robLinear(const std::vector<int>& nums, int start, int end) {
        int rob1 = 0; // Tracks maximum profit two houses back
        int rob2 = 0; // Tracks maximum profit one house back
        
        for (int i = start; i <= end; ++i) {
            int currentMax = std::max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = currentMax;
        }
        
        return rob2;
    }
};

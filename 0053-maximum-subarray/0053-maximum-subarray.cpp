class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            currentSum = max(nums[i] , nums[i] + currentSum);
            maxSum  = max(currentSum, maxSum);
        }

        return maxSum;
    }
};
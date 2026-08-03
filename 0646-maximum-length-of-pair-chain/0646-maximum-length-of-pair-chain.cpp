class Solution {
public:
    int t[1001][1001];
    int solve(int idx, int prev, vector<vector<int>> &nums){
        if(idx >= nums.size()){
            return 0;
        }
        if(prev != -1 && t[idx][prev] != -1){
            return t[idx][prev];
        }

        // pick
        int pick = 0;
        if(prev == -1 || nums[prev][1] < nums[idx][0]){
            pick = 1 + solve(idx + 1, idx, nums);
        }

        // skip 
        int skip = solve(idx + 1, prev, nums);

        if(prev != -1){
            t[idx][prev] = max(pick, skip);
        }

        return max(pick, skip);
    }
    int findLongestChain(vector<vector<int>>& nums) {
        memset(t, -1, sizeof(t));
        sort(nums.begin(), nums.end());
        return solve(0, -1, nums);
    }
};
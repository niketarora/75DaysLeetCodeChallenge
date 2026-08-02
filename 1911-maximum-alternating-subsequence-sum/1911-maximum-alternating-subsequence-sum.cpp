class Solution {
public:
    long long t[100001][2];
    long long solve(int idx, bool flag, vector<int> &nums){
        if(idx >= nums.size()){
            return 0;
        }
        if(t[idx][flag] != -1) 
            return t[idx][flag];

        // take(pick)
        long long val = nums[idx];
        if(flag == false){
            val = -val;
        }
        long long take = val + solve(idx+1, !flag, nums);

        // skip
        long long skip = solve(idx+1, flag, nums);

        return t[idx][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int flag = 1;
        memset(t, -1, sizeof(t));
        long long res = solve(0, true, nums);
        return res;
    }
};
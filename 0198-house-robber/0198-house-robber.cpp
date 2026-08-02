class Solution {
public:
    int t[101];
    int func(int idx, vector<int> &nums){
        if (idx >= nums.size())
            return 0;

        if(t[idx] != -1){
            return t[idx];
        }
        int pick = nums[idx] + func(idx + 2, nums);
        int notPick = func(idx + 1, nums);

        return t[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int res = func(0, nums);
        return res;
    }
};
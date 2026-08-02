class Solution {
public:
    int t[101];
    int func(int idx, vector<int> &nums, int size){
        if (idx > size)
            return 0;

        if(t[idx] != -1){
            return t[idx];
        }
        int pick = nums[idx] + func(idx + 2, nums, size);
        int notPick = func(idx + 1, nums, size);

        return t[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int take_0th_house = func(0, nums, n-2);

        memset(t, -1, sizeof(t));
        int take_1st_house = func(1, nums, n-1);

        return max(take_0th_house, take_1st_house);
    }
};
class Solution {
public:
    void combination(int idx, int target, vector<int>& nums, vector<vector<int>>& res, vector<int> ds){
        if(idx == nums.size()){
            if(target == 0) 
                res.push_back(ds);
            return;
        }
        // picking up the element
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            combination(idx, target-nums[idx], nums, res, ds);
            ds.pop_back();
        }

        combination(idx+1, target, nums, res, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        combination(0, target, candidates, res, ds);
        return res;
    }
};
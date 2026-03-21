class Solution {
public:
    void allSubsets(int idx, vector<int> ds, vector<int>& nums, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }
        // pick the element
        ds.push_back(nums[idx]);
        allSubsets(idx+1, ds, nums, ans);
        ds.pop_back();

        // without pick the element
        allSubsets(idx+1, ds, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        allSubsets(0, ds, nums, ans);
        return ans;
    }
};
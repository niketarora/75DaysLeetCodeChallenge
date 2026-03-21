class Solution {
public:
    void allSubsets(int idx, vector<int> ds, vector<int>& nums, set<vector<int>>& ans){
        if(idx == nums.size()){
            sort(ds.begin(), ds.end());
            ans.insert(ds);
            return;
        }
        // pick the element
        ds.push_back(nums[idx]);
        allSubsets(idx+1, ds, nums, ans);
        ds.pop_back();
            
        // without pick the element
        allSubsets(idx+1, ds, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> ds;
        allSubsets(0, ds, nums, ans);
        for(auto ele : ans){
            res.push_back(ele);
        }
        return res;
    }
};
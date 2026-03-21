class Solution {
public:

    // THIS IS THE METHOD WHERE WE ARE DECIDING EITHER PICK OR NO PICK
    // void combination(int idx, int target, vector<int>& nums, set<vector<int>>& res, vector<int> ds){
    //     if(idx == nums.size()){
    //         if(target == 0){
    //             sort(ds.begin(), ds.end());
    //             res.insert(ds);
    //         }
    //         return;
    //     }
    //     // picking up the element
    //     if(nums[idx] <= target){
    //         ds.push_back(nums[idx]);
    //         combination(idx+1, target-nums[idx], nums, res, ds);
    //         ds.pop_back();
    //     }

    //     combination(idx+1, target, nums, res, ds);
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     set<vector<int>> res;
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     combination(0, target, candidates, res, ds);
    //     for(auto ele : res){
    //         ans.push_back(ele);
    //     }
    //     return ans;
    // }



    // NOW WE WILL SEE THE METHOD OF PICK IDX 1 OR 2 OR 3 OR 4.....
    void combination(int idx, int target, vector<int>& nums, set<vector<int>>& res, vector<int>& ds){
        if(target == 0){
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target)   break;
            ds.push_back(nums[i]);
            combination(i+1, target-nums[i], nums, res, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> ds;
        combination(0, target, candidates, res, ds);
        for(auto ele : res){
            ans.push_back(ele);
        }
        return ans;
    }
};
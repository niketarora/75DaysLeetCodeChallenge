class Solution {
public:
    void combination(int idx, vector<int> &ds, vector<int>& candidates, int target, vector<vector<int>> &ans){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        // pick 
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            combination(idx, ds, candidates, target-candidates[idx], ans);
            ds.pop_back();
        }
        // not pick
        combination((idx+1), ds, candidates, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        combination(0, ds, candidates, target, ans);
        return ans;
    }
};
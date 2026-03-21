class Solution {
public:
    void combination(int idx, int target, int k, vector<vector<int>>& res, vector<int>& ds){
        if(target == 0 && ds.size() == k){
            res.push_back(ds);
            return;
        }
        if(target < 0 || idx > 9 || ds.size() > k) return;

        // pick
        ds.push_back(idx);
        combination(idx+1, target-idx, k, res, ds);
        ds.pop_back();

        // not pick
        combination(idx+1, target, k, res, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        combination(1, n, k, res, ds);
        return res;
    }
};
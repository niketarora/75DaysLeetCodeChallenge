class Solution {
public:
    void permutation(vector<int> &ds, vector<int>& nums, vector<int> &freq, vector<vector<int>> &ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutation(ds, nums, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(), 0);
        permutation(ds, nums, freq, ans);
        return ans;
    }
};
class Solution {
public:
    void allPermutations(vector<int> ds, vector<int>& nums, int freq[], set<vector<int>>& res){
        if(ds.size() == nums.size()){
            res.insert(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                allPermutations(ds, nums, freq, res);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ds;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++)    freq[i] = 0;
        allPermutations(ds, nums, freq, res);
        for(auto ele : res){
            ans.push_back(ele);
        }
        return ans;
    }
};
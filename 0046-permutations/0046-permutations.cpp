class Solution {
public:
    void allPermutations(vector<int> ds, vector<int>& nums, int freq[], vector<vector<int>>& res){
        if(ds.size() == nums.size()){
            res.push_back(ds);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++)    freq[i] = 0;
        allPermutations(ds, nums, freq, res);
        return res;
    }
};
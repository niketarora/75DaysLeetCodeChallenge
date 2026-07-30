class Solution {
public:
    void subsetSum(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &answer){
        answer.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i] == nums[i-1])  continue;
            ds.push_back(nums[i]);
            subsetSum(i+1, nums,  ds, answer);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        subsetSum(0, nums, ds, answer);
        return answer;
    }
};
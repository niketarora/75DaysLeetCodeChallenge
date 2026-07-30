class Solution {
public:
    void powerSet(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &answer){
        if(idx == nums.size()){
            answer.push_back(ds);
            return;
        }
        // pick
        ds.push_back(nums[idx]);
        powerSet(idx+1, nums, ds, answer);
        ds.pop_back();

        // not pick
        powerSet(idx+1, nums, ds, answer);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> answer;
        powerSet(0, nums, ds, answer);
        return answer;
    }
};
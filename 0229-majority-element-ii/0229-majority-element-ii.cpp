class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        int limit = nums.size()/3;

        for(auto it : mp){
            if(it.second > limit)   ans.push_back(it.first);
        }
        return ans;
    }

};
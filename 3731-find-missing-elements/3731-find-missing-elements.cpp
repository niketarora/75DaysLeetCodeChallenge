class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minnum = INT_MAX, maxnum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxnum = max(maxnum, nums[i]);
            minnum = min(minnum, nums[i]);
        }
        vector<int> t(maxnum+1, 0);
        for(int i=0; i<nums.size(); i++){
            t[nums[i]] = 1;
        }  
        vector<int> ans;
        for(int i=minnum; i<maxnum; i++){
            if(t[i] != 1)   ans.push_back(i);
        }
        return ans;
    }
};
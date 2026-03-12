class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // USING HASH MAPS
        vector<int> result;
        int s = nums.size();
        unordered_map<int,int> map;
        for(int i=0; i<s; i++){
            int rem = target - nums[i];
            if(map.find(rem) != map.end()){
                result.push_back(map[rem]);
                result.push_back(i);
            }
            else   map[nums[i]] = i;
        }
        return result;
    }
};
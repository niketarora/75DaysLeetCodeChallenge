class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int j = start - 1;
        while(i<nums.size() || j>=0){
            if(i<nums.size()){
                if(nums[i] == target)   return abs(i - start);
                i++;
            }
            if(j>=0){
                if(nums[j] == target)   return abs(j - start);
                j--;
            }
        }
        return -1;
    }
};
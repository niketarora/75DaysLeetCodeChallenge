class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 1, i = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[i] != nums[j]){ 
                x++; i++;
                nums[i] = nums[j];
            }
        }
        return x;
    }
};
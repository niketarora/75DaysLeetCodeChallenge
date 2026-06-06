class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0; 
        int j = nums.size() - 1;
        int l = 0;
        while(l <= j){
            if(nums[l] == 0){
                swap(nums[i], nums[l]);
                i++;
                l++;
            }
            else if(nums[l] == 1){
                l++;
            }
            else{
                swap(nums[j], nums[l]);
                j--;
            }
        }
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // LINEAR SOLUTION
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;

        // BINARY SOLUTION
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l <= h){
            int mid = (l + h)/2;
            if(nums[mid] == target) return mid;
            if(nums[l] <= nums[mid]){ // left sorted
                if(nums[l] <= target && target <= nums[mid])
                    h = mid - 1;
                else    
                    l = mid + 1;
            }
            else{   // right sorted
                if(nums[mid] <= target && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};
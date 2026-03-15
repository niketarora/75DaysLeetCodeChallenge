class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // the approach is to put all the numbers at there rigth index
        // by swap and then itrate at the end to find the elemet that are 
        // at the wrong spot and push them in array
        int n = nums.size();
        int i = 0; 
        while(i<n){
            int correctIdx = nums[i]-1;
            if(correctIdx == i || nums[correctIdx] == nums[i])    i++;
            else swap(nums[correctIdx] , nums[i]);
        }
        vector<int> v;
        for(int i=0; i<n; i++){
            if(nums[i] != i+1)  v.push_back(i+1);
        }
        return v;
    }
};
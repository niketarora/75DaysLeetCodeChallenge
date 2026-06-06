class Solution {
public:
    void reversePart(int i, int j, vector<int> &a){
        while(i<=j){
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break; 
            }
        }
        if(idx == -1){
            reversePart(0,n-1,nums);
        }
        else{
            reversePart(idx+1,n-1,nums);
            int j = -1;
            for(int i=idx+1; i<n; i++){
            if(nums[i]>nums[idx]){
                j = i;
                break;
            }
        }
            int temp = nums[idx];
            nums[idx] = nums[j];
            nums[j] = temp;
        }
    }
};
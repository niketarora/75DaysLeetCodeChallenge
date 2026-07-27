class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int largest=0;
        int second=0;
        int j=0;
        int k=0;
        for(int i=0; i<n; i++){
            if(nums[i]>=largest){
                k=j;
                j=i;
                second = largest;
                largest = nums[i];
            }
            else if (nums[i] > second && nums[i] != largest){
                second = nums[i];
                k=i;
            }
        }
        return ((nums[k]-1)*(nums[j]-1));
    }
};
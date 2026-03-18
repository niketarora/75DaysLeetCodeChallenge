class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // using prefix and sufix products
        int n = nums.size();
        int prefixP[n];
        int sufixP[n];
        // prefix product
        for(int i=0; i<n; i++){
            if(i == 0)  prefixP[i] = 1;
            else    prefixP[i] = nums[i-1] * prefixP[i-1]; 
        }
        // sufix product
        for(int i=n-1; i>=0; i--){
            if(i == n-1)  sufixP[i] = 1;
            else    sufixP[i] = nums[i+1] * sufixP[i+1]; 
        }
        for(int i=0; i<n; i++){
            nums[i] = prefixP[i] * sufixP[i]; 
        }
        return nums;
    }
};
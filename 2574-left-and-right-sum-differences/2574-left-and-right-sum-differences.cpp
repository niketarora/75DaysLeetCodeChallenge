class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        int sum = 0;
        for(int i=1; i<n; i++){
            sum += nums[i-1];
            leftSum[i] = sum;
        }
        sum = 0;
        for(int j=n-2; j>=0; j--){
            sum += nums[j+1];
            rightSum[j] = sum;
        }
        for(int i=0; i<n; i++){
            nums[i] = abs(leftSum[i] - rightSum[i]);
        }
        return nums;
    }
};
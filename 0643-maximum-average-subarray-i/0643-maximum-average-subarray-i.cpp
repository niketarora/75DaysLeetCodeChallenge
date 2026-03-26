class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // int i = 0;
        // int j = k-1;
        // double maximum = INT_MIN;
        // while(j<nums.size()){
        //     double sum = 0;
        //     for(int x=0; x<k; x++){
        //         sum += nums[x+i];
        //     }
        //     double avg = sum/k;
        //     maximum = max(maximum, avg);
        //     j++;
        //     i++; 
        // }
        // return maximum;


        // NOW USE SLIDING WINDOW
        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        double maxSum = sum;
        for(int i=k; i<nums.size(); i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxSum = max(sum, maxSum);
        }
        return maxSum/k;
    }
};
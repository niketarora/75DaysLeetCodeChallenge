class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(target < (numbers[i] + numbers[j]))  j--;
            else if(target > (numbers[i] + numbers[j]))   i++;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};
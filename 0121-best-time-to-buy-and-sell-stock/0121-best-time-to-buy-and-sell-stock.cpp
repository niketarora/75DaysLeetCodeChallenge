#include <climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = INT_MAX;
        int max=0;
        for(int i=0; i<n; i++){
            if(prices[i] < minSoFar)     minSoFar = prices[i];
            if(prices[i] - minSoFar > max)   max = prices[i] - minSoFar;
        }
        return max;
    }
};
class Solution {
public:
    int count(int n){
        int count = 0;
        while (n != 0) {
            n &= (n - 1); // Clears the lowest set bit
            count++;      // Increments the count for each set bit found
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0 ; i<=n; i++){
            int res = count(i);
            ans.push_back(res);
        }
        return ans;
    }
};
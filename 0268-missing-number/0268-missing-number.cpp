class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i<n){
            if(arr[i] == i || arr[i] == n) i++;
            else   swap(arr[i] , arr[arr[i]]);
        }
        for(int i=0; i<n; i++){
            if(i != arr[i]) return i;
        }
        return n;
    }
};
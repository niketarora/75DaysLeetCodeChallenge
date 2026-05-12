// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // linear search
        // int ans = 0;
        // for(int i=0; i<=n; i++){
        //     bool res = isBadVersion(i);
        //     if(res){
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        // binary search
        if(n == 1)  return 1; 
        int i = 1;
        int j = n;
        int ans = -1;
        while(i<=j){
            int mid = i + (j-i)/2;
            int res = isBadVersion(mid);
            if(res){
                j = mid - 1;
                ans = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};
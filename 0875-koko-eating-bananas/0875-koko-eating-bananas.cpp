class Solution {
public:
    bool check(int speed, vector<int>& piles, int h){
        long long count = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            if(piles[i]%speed != 0)   count += (long long)((piles[i]/speed)+1);
            else    count += (long long)(piles[i]/speed);
        }
        if(count>(long long)h) return false;
        else    return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = -1;
        for(int i=0; i<n; i++){
            if(max<piles[i])    max = piles[i];
        }
        int low = 1;
        int high = max;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(check(mid,piles,h)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};
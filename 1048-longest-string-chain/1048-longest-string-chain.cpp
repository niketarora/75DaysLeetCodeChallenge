class Solution {
public:
    int t[1001][1001];
    bool isPred(string &prev, string &curr){
        int m = prev.length();
        int n = curr.length();

        if(m >= n || n-m != 1){
            return false;
        }
        int i=0, j=0;

        while(i<m && j<n){
            if(prev[i] == curr[j])
                i++;
            j++;
        }
        return i==m;
    }
    static bool cmp(string &word1, string &word2){
        return word1.length() < word2.length();
    }
    int lis(vector<string>& words, int n, int prev, int curr){
        if(curr == n){
            return 0;
        }

        if(prev != -1 && t[prev][curr] != -1){
            return t[prev][curr];
        }

        int pick=0, notpick=0;

        // pick
        if(prev == -1 || isPred(words[prev], words[curr])){
            pick = 1 + lis(words, n, curr, curr+1);
        }

        // not pick
        notpick = lis(words, n, prev, curr+1);

        if(prev != -1){
            t[prev][curr] = max(pick, notpick);
        }

        return max(pick, notpick); 
    }
    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        int n = words.size();
        sort(begin(words), end(words), cmp);

        return lis(words, n, -1, 0);
    }
};
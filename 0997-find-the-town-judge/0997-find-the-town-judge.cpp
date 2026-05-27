class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1, 0);
        
        for (const auto& relation : trust) {
            count[relation[0]]--; // This person trusts someone else
            count[relation[1]]++; // This person is trusted
        }
        
        for (int i = 1; i <= n; i++) {
            // The judge is trusted by exactly n - 1 people and trusts nobody
            if (count[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        vector<int> hash(256, 0);
        int maxLength = 0;
        while(j < s.size()) {
            hash[s[j]]++;
            while(hash[s[j]] > 1) {
                hash[s[i]]--;
                i++;
            }

            maxLength = max(maxLength, (j - i + 1));
            j++;
        }
        return maxLength;
    }
};
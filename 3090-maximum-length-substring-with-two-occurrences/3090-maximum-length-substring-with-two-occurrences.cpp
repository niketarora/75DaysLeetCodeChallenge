class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> v(26,0);
        int left = 0;
        int maxLen = 0;

        for(int right=0; right<s.length(); right++){
            v[s[right]-'a']++;

            while(v[s[right] - 'a'] > 2){
                v[s[left]-'a']--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
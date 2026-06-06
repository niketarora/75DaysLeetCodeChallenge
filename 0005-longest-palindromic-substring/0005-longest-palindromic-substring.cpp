class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, len = 0;
        for (int i = 0; i < s.length(); i++) {
            // Check both odd and even length palindromes
            int l1 = expand(s, i, i), l2 = expand(s, i, i + 1);
            int curLen = max(l1, l2);
            if (curLen > len) {
                len = curLen;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, len);
    }
private:
    int expand(string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
        return r - l - 1; //
    }
};

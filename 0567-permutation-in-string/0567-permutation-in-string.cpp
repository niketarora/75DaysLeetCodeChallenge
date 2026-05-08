class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> s1_count(26, 0), window_count(26, 0);

        // Fill frequency for s1 and the first window of s2
        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = 0; i < n2 - n1; i++) {
            if (s1_count == window_count) return true;
            
            // Move window: remove the leftmost character, add the next rightmost
            window_count[s2[i] - 'a']--;
            window_count[s2[i + n1] - 'a']++;
        }

        // Check the last window
        return s1_count == window_count;
    }
};

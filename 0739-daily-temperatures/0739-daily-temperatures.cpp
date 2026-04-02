class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temp[i] > st.top().first) {
                int index = st.top().second;
                st.pop();
                ans[index] = i - index;
            }
            st.push({temp[i], i});
        }

        return ans;
    }
};

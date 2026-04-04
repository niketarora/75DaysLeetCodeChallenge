class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr);
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int r = 1;

        for (int i = 0; i < temp.size(); i++) {
            if (i == 0 || temp[i] != temp[i - 1]) {
                rank[temp[i]] = r;
                r++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }
        

        return arr;
    }
};
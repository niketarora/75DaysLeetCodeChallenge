class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows>0){
            vector<int> first = {1};
            ans.push_back(first);
        }
        if(numRows>1){
            vector<int> second = {1,1};
            ans.push_back(second);
        }
        for(int i=2; i<numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<i; j++){
                int res = ans[i-1][j] + ans[i-1][j-1];
                temp.push_back(res);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
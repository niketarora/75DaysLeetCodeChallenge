class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(i==j)    continue;
                else{
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }
        return mat;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool ans = true;
        for(int i=0; i<4; i++){
            rotation(mat);
            bool temp = true;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] != target[i][j]){
                        temp = false;
                        break;
                    }
                }
            }
            if(temp == true){
                ans = true;
                break;
            }
            else
                ans = false;
        }
        return ans;
    }
};
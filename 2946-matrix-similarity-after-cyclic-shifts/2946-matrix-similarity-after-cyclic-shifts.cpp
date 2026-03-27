class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> v = mat;

        //k = k % m;

        for(int x = 0; x < k; x++){
            for(int i = 0; i < n; i++){
                if(i % 2){  // right shift
                    int temp = mat[i][m-1];
                    for(int j = m-1; j > 0; j--){
                        mat[i][j] = mat[i][j-1];
                    }
                    mat[i][0] = temp;
                }
                else{  // left shift
                    int temp = mat[i][0];
                    for(int j = 0; j < m-1; j++){
                        mat[i][j] = mat[i][j+1];
                    }
                    mat[i][m-1] = temp;
                }
            }
        }

        return mat == v;
    }
};
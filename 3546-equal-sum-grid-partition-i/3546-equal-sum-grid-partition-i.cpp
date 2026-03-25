class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m,0);
        vector<long long> col(n,0);
        for(int i=0; i<m; i++){
            long long sum=0;
            for(int j=0; j<n; j++){
                sum += (long long)grid[i][j];
            }
            row[i] = sum;
        }

        for(int j=0; j<n; j++){
            long long sum=0;
            for(int i=0; i<m; i++){
                sum += (long long)grid[i][j];
            }
            col[j] = sum;
        }
        long long rowSum = 0;
        long long colSum = 0;
        for(int i=0; i<row.size(); i++){
            rowSum += (long long)row[i];
        }
        for(int i=0; i<col.size(); i++){
            colSum += (long long)col[i];
        }
        long long currentSum = 0;
        for(int i=0; i<row.size(); i++){
            currentSum += row[i];
            if(currentSum == (rowSum-currentSum))   return true;
        }
        currentSum = 0;
        for(int i=0; i<col.size(); i++){
            currentSum += col[i];
            if(currentSum == (rowSum-currentSum))   return true;
        }
        return false;
    }
};
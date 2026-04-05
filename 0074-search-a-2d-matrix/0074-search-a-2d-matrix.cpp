class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = m*n;
        int l = 0;
        int h = size - 1;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[mid/m][mid%m] == target)   return true;
            else if(matrix[mid/m][mid%m] > target)   h = mid - 1;
            else    l = mid + 1;
        }
        return false;
    }
};
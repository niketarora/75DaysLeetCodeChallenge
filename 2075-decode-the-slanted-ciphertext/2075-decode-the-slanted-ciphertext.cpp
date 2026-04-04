class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size = encodedText.size();
        if(size == 0)   return "";
        int cols = size/rows;
        vector<vector<char>> v(rows,vector<char>(cols,' '));
        int count = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                v[i][j] = encodedText[count];
                count++;
            }
        }
        string res = "";
        for(int j=0; j<cols; j++){
            int i = 0;
            int k = j;
            while(i<rows && k<cols){
                res += v[i][k];
                i++; k++;
            }
        }
        int idx = 0;
        for(int i=res.size()-1; i>0; i--){
            if(res[i] != ' '){
                idx = i;
                break;
            }
        }
        string ans = "";
        for(int i=0; i<=idx; i++){
            ans += res[i];
        }
        return ans;
    }
};
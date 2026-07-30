class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        int assign = 2;
        // unordered_map<int, int> mp;
        // for(char &ch : word){
        //     if(assign > 9){
        //         assign = 2;
        //     }
        //     mp[assign]++;
        //     res += mp[assign];

        //     assign++;
        // }

        vector<int> v(10, 0);
        for(int i=0; i<word.size(); i++){
            if(assign > 9)  assign = 2;
            
            v[assign]++;
            res += v[assign];
            assign++;
        }

        return res;
    }

};
class Solution {
public:
    int minimumPushes(string word) {

        // int res = 0;
        // int assign = 2;
        // using map
        // unordered_map<int, int> mp;
        // for(char &ch : word){
        //     if(assign > 9){
        //         assign = 2;
        //     }
        //     mp[assign]++;
        //     res += mp[assign];

        //     assign++;
        // }
        // using vector 
        // vector<int> v(10, 0);
        // for(int i=0; i<word.size(); i++){
        //     if(assign > 9)  assign = 2;
            
        //     v[assign]++;
        //     res += v[assign];
        //     assign++;
        // }/


        // BETTER METHOD
        int res = 0;
        vector<int> v(26,0);
        for(int i=0; i<word.size(); i++){
            v[word[i]-'a']++;
        }
        sort(v.begin(), v.end(), [](int a, int b) {
            return a > b; 
        });

        for(int i=0; i<26; i++){
            if (v[i] == 0) break;

            int pushes = (i / 8) + 1;
            res += v[i] * pushes;
        }


        return res;
    }

};
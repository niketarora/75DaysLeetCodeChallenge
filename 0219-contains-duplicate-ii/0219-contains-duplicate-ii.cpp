class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // USING UNORDERED_MAP
        // unordered_map<int, int> mp;
        // for(int i=0; i<nums.size(); i++){
        //     if(mp.find(nums[i]) != mp.end()){
        //         if((i - mp[nums[i]]) <= k)  
        //             return true;
        //     }
        //     mp[nums[i]] = i;
        // }
        // return false;



        // USING SLINGDING WINDOW + SET
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                return true;
            }

            st.insert(nums[i]);

            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};
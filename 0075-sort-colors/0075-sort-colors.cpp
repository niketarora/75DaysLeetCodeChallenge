class Solution {
public:
    void sortColors(vector<int>& nums) {
        int noz=0, noo=0, notw=0;
        for(int i=0; i<=nums.size()-1; i++){
            if(nums[i] == 0)  noz++;
            else if(nums[i] == 1)  noo++;
            else  notw++;
        }
        for(int i=0;i<=nums.size()-1;i++){
            if(i<noz) nums[i] = 0;
            else if(i<(noo+noz)) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};
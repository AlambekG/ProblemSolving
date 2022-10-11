class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -99999, sm = 0;
        for(auto i : nums){
            sm += i;
            if(sm > mx) mx = sm;
            if(sm < 0) sm = 0;
        }
        return mx;
    }
};
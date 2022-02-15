class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map <int, int> mp;
        
        for(auto i:nums) mp[i] ++;
        for(auto i:nums) if(mp[i] == 1) ans = i;
        return ans;
    }
};
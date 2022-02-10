class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        
        int sums = 0, cnt = 0;
        mp[0] = 1;
        for(auto i : nums){
            sums += i;
            if(mp[sums - k]) cnt += mp[sums-k];
            cout << mp[sums - k] << ' ' << sums - k << endl;
            mp[sums] ++;
        }
        return cnt;
    }
};
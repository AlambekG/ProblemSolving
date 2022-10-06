class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map <int, int> mp;
        
        vector <int> v;
        for(auto i: nums){
            if(!mp[i]) v.push_back(i);
            mp[i] ++;
        }
        
        int sm = 0;
        sort(v.begin(), v.end());
        for(auto i: v)
            mp[i] = i * mp[i];
        
        int n = v[v.size() - 1];
        int dp[n + 10][2];
        for(int i = 0;i <= n;i ++){
            dp[i][1] = dp[i][0] = 0;
        }
        
        for(int i = 1;i <= n;i ++){
            dp[i][1] = mp[i] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        
        return max(dp[n][1], dp[n][0]);
    }
};
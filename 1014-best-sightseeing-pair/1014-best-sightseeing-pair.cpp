class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int dp[n + 10];
        
        for(int i = 0;i < n;i ++){
             dp[i] = values[i] - i;
        }
        dp[n] = -99999;
        for(int i = n - 1;i >= 0;i --){
            dp[i] = max(dp[i + 1], dp[i]);
        }
        
        int ans = 0;
        for(int i = 0;i < n - 1;i ++){
            ans = max(ans, values[i] + dp[i + 1] + i);
            cout << values[i] << ' '<< dp[i + 1] << ' ' << i << endl;
        }
        return ans;
    }
};
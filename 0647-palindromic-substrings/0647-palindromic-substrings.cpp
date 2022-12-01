class Solution {
public:
    int dp[1001][1001];
    
    int countSubstrings(string s) {
        for(int i = 0;i < s.size();i ++){
            dp[i][i] = 1;
        }
        
        for(int cl = 2;cl <= s.size(); cl ++){
             for(int i = 0;i < s.size() - cl + 1;i ++){
                 int j = i + cl - 1;
                 if(cl == 2 && s[i] == s[j]){
                     dp[i][j] = 1;
                 }
                 else if (s[i] == s[j]){
                     dp[i][j] = dp[i + 1][j - 1];
                 }
             }
        }
        
        int cnt = 0;
        for(int i = 0;i < s.size();i ++){
            for(int j = i;j < s.size();j ++){
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};
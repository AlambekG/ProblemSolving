class Solution {
public:
    int dp[1001][1001];
    
    int longestPalindromeSubseq(string s) {
        
         for(int i = 0;i < s.size();i ++)
             dp[i][i] = 1;
         
         for(int cl = 2; cl <= s.size();cl ++){
             for(int i = 0;i < s.size() - cl + 1;i ++){
                  int j = i + cl - 1;
                  if(s[i] == s[j] && cl == 2){
                      dp[i][j] = 2;
                  }
                  else if(s[i] == s[j]){
                      dp[i][j] = dp[i + 1][j - 1] + 2;
                  }
                  else{
                      dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                  }
             }
         }
         return dp[0][s.size() - 1];
    }
};
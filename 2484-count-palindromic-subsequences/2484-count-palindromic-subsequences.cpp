class Solution {
public:
    
    int dk[10020][11];
    long long dp[10020][11][11];  
    
    int dk2[10020][11], mod = 1e9 + 7, x;
    long long dp2[10020][11][11]; 
    
    int countPalindromes(string s) {
        if(s.size() < 5) return 0;
        
        for(int i = 0;i < s.size();i ++){
            x = int(s[i] - 48);
            dk[i][x] = 1;
            for(int k = 0;k < 10;k ++){
                if(i > 0)
                    for(int c = 0;c < 10;c ++)
                        dp[i][k][c] = dp[i - 1][k][c];
                if(i > 0){
                    dk[i][k] += dk[i - 1][k];
                    dp[i][k][x] += dk[i - 1][k];  
                } 
            }
        }
        for(int i = s.size() - 1;i >= 0;i --){
            x = int(s[i] - 48);
            dk2[i][x] = 1;  
            for(int k = 0;k < 10;k ++){
                for(int c = 0;c < 10;c ++)
                    dp2[i][k][c] = dp2[i + 1][k][c];
                dk2[i][k] += dk2[i + 1][k];
                dp2[i][k][x] += dk2[i + 1][k];  
            }
        }
        int cnt = 0;        
        for(int i = 2;i < s.size() - 2;i ++){
            long long val = 0;
            for(int k = 0;k < 10;k ++){
                for(int c = 0;c < 10;c ++){
                    val += (dp[i - 1][k][c] * dp2[i + 1][k][c]) % mod;
                }
            }
            cnt = (cnt + val) % mod;
        }
        
        return cnt;
    }
};
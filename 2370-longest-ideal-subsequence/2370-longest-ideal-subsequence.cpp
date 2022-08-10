class Solution {
public:
    int longestIdealString(string s, int k) {
         int ar[28] = {0};
         
         for(int i = 0;i < s.size();i ++){
                int ch = int(s[i]) - 96, val = 0;
                for(int j = max(ch - k, 1);j <= min(ch + k, 26);j ++){
                      val = max(val, ar[j] + 1);
                }
                ar[ch] = val;
         }
         int ans = 0;
         for(int i = 1;i <= 26;i ++) ans = max(ans, ar[i]);
         return ans;
    }
};
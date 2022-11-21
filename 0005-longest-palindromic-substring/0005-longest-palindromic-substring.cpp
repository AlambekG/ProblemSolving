class Solution {
public:
    string even(string s){
        string ans = "";
        
        int sz = 1;
        
        pair <int, int> pp;
        int mx = 0;
        
        for(int i = 0;i < s.size();i ++){
            int r = i + sz, l = i;
             while(r < s.size() && l > -1 && s[l] == s[r]){
                 if(r - l + 1 > mx){
                     mx = r - l + 1;
                     pp = make_pair(l, r);
                 }
                 r ++;
                 l --;
             }
        }
        for(int i = pp.first;i <= pp.second;i ++)
             ans += s[i];
        
        return ans;
    }
    string odd(string s){
        string ans = "";
        
        int sz = 2;
        
        pair <int, int> pp;
        int mx = 0;
        
        for(int i = 0;i < s.size();i ++){
            int r = i + sz, l = i;
             while(r < s.size() && l > -1 && s[l] == s[r]){
                 if(r - l + 1 > mx){
                     mx = r - l + 1;
                     pp = make_pair(l, r);
                 }
                 r ++;
                 l --;
             }
        }
        for(int i = pp.first;i <= pp.second;i ++)
             ans += s[i];
        
        return ans;
    }
    
    
    string longestPalindrome(string s) {
         string ans1 = even(s);
         string ans2 = odd(s);
        
         if(ans1.size() > ans2.size()) return ans1;
         return ans2;
    }
};
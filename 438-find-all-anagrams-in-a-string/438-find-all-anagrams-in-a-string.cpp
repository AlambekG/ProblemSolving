class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
          vector <int> ans; 
          if(p.size() > s.size()) return ans;
          vector<int> mp(26,0), mm(26, 0);
        
          for(int i = 0;i < p.size();i ++){
                 mp[p[i] - 'a'] ++;
                 mm[s[i] - 'a'] ++;
          }
        
          int m = p.size();
          for(int i = m;i < s.size();i ++){
                if(mp == mm){
                     ans.push_back(i - m);
                } 
                mm[s[i] - 'a'] ++;
                mm[s[i - m] - 'a'] --;
          }
         if(mm == mp) ans.push_back(s.size() - m);
         return ans;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        int n = s1.size();
        
        vector<int> mp(26, 0), mm(26, 0);
        
        for(auto i : s1)
             mp[i - 'a'] ++;
        
        int l = 0;
        for(int i = 0;i < s1.size() - 1;i ++)
             mm[s2[i] - 'a'] ++;
        for(int i = s1.size() - 1;i < s2.size();i ++){
              mm[s2[i] - 'a'] ++;
              if(mp == mm) return true;
              mm[s2[l] - 'a'] --;
              l ++;
            
             
        }
        return false;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
          unordered_map <char, int> mp, mm;
        
          for(auto i : s)
               mp[i] ++;
          for(auto i :t)
               mm[i] ++;
        
          for(auto i : t){
                if(mm[i] != mp[i]){
                     return i;
                }
          }
        return 'a';
    }
};
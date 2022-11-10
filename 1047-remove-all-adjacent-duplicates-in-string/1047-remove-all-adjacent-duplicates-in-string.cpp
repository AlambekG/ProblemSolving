class Solution {
public:
    string removeDuplicates(string s) {
        int l = 0;
        
        unordered_map <int, int> mp;
        for(int i = 1;i < s.size();i ++){
            if(l != i && l > -1 && s[l] == s[i]){
                mp[l] = mp[i] = 1;
                while(mp[l]) l --;
            }
            else l = i;
        }
        
        string a;
        for(int i = 0;i < s.size();i ++)
            if(!mp[i]) a += s[i];
        return a;
    }
};
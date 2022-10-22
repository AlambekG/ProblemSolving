class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = 0, l2 = 0;
        
        bool ans = true;
        while(true){
            if(l1 >= s.size()) break;
            
            if(l1 < s.size() && l2 >= t.size()){
                ans = false;
                break;
            }
            
            if(s[l1] == t[l2])
                while(l1 < s.size() && l2 < t.size() && s[l1] == t[l2]){
                    l1 ++;l2 ++;
                }
            else
                while(l2 < t.size() && s[l1] != t[l2]) l2 ++;
            if(s[l1] == t[l2]) l1 ++, l2 ++;
        }
        
        return ans;
    }
};
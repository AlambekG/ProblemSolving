class Solution {
public:
    bool rotateString(string s, string goal) {
         int n = s.size() + 1;
         
          while(n -- ){
                if(s == goal) return true;
                s += s[0];
                s.erase(0, 1);
          }
        return false;
    } 
};
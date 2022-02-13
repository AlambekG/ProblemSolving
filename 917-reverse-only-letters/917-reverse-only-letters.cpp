class Solution {
public:
    string reverseOnlyLetters(string s) {
          int l = 0, r = s.size() - 1;
          
          while(l < r){
               while(l < s.size() && !isalpha(s[l])) l ++;
               while(r > -1 && !isalpha(s[r])) r --;
               if(l < r) swap(s[l], s[r]);
               l ++;
               r --;
          }
          return s;
    }
};
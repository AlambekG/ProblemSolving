class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = "";
        while(x){
            s += char(x % 10 + 48);
            x /= 10;
        }
        
        string a = s;
        reverse(a.begin(), a.end());
        return a == s;
    }
};
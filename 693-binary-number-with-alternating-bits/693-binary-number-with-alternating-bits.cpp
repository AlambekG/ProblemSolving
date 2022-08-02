class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s;
        while(n > 1){
            if(n % 2) s += '1';
            else s += '0';
            n /= 2;
        }
        if(n % 2) s += '1';
            else s += '0';
        for(int i = 1;i < s.size();i ++)
             if(s[i] == s[i - 1]) return false;
        std::cout<<s;
        return true;
    }
};
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a, b, l, o, n, s;
        a = b = l = o = n = 0;
        
        for(auto i : text){
             if(i == 'b') b ++;
             if(i == 'a') a ++;
             if(i == 'l') l ++;
             if(i == 'o') o ++;
             if(i == 'n') n ++;
        }
        
        if(b < a) a = b;
        if(n < a) a = n;
        if(int(l >> 1) < a) a = l >> 1;
        if(int(o >> 1) < a) a = o >> 1;
        
        return a;
    }
};
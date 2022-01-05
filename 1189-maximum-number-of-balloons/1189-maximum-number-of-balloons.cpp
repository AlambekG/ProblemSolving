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
        if(int(l / 2) < a) a = l / 2;
        if(int(o / 2) < a) a = o / 2;
        
        return a;
    }
};
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
        
        a = min(a, b);
        a = min(a, n);
        a = min(a, l / 2);
        a = min(a, o / 2);
        return a;
    }
};
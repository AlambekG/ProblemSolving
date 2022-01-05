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
        
        int cnt = 0;
        while(1){
            if(b) b--;
            else break;
            if(a) a--;
            else break;
            if(l > 1) l -= 2;
            else break;
            if(o > 1) o -= 2;
            else break;
            if(n) n--;
            else break;
            cnt ++;
        }
        return cnt;
    }
};
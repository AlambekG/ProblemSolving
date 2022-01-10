class Solution {
public:
    string addBinary(string a, string b) {
         if(b.size() > a.size()) swap(a, b);
         
         int i = a.size() - 1, j = b.size() - 1, d = 0;
         while(i > -1 || j > -1 || d){
               int x = 0;
               if(j > -1 && b[j] == '1') x ++;
               if(i > -1 && a[i] == '1') x ++;
               if(d) x ++;
               
               if(x == 2) {
                     x = 0;
                     d = 1;
               }
               else if(x == 3){
                    x = 1;
                    d = 1;
               }
               else  d = 0;
               
               if(i > -1) a[i] = char(x + 48);
               else a = char(x + 48) + a;
               i --;
               j --;
         }
        return a;
    }
};
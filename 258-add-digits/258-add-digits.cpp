class Solution {
public:
    int addDigits(int num) {
         while(num > 9){
              int x = num;
              num = 0;
              while(x > 0){
                   num += (x % 10);
                   x /= 10;
              }
         }
         return  num;
         
    }
};
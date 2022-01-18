
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       for(int i = 0; i < flowerbed.size(); ++i){
           if(flowerbed[i] != 1){
               int left = 0;
               int right = 0;
               if((i - 1) >= 0){
                   left = flowerbed[i-1];
               }
               if((i + 1) < flowerbed.size()){
                   right = flowerbed[i+1];
               }
               if(left == 0 && right == 0){
                   flowerbed[i] = 1;
                   n -= 1;
               }
           }
       }
        if(n <= 0) return true;
        return false;
    }
};
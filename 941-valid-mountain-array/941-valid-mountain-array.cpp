class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
         if(arr.size() < 3) return false;
         
         int flag = 0;
         for(int i = 1;i < arr.size();i ++){
              if(flag){
                   if(arr[i] >= arr[i - 1]) return false;
                   else flag ++;
              }
              else{
                  if(arr[i] == arr[i - 1]) return false;
                  if(arr[i] < arr[i - 1]) flag = 1;
              }
         }
        if(!flag || arr[1] <= arr[0]) return false;
        return true;
    }
};
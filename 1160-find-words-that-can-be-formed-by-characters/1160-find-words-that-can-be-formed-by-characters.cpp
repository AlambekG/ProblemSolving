class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
         unordered_map <char, int> mp;
         for(auto i : chars) mp[i] ++;
         
         int ans = 0;
         for(auto i : words){
               unordered_map <char, int> mm = mp;
               bool flag = true;
               for(auto j : i){
                    mm[j] --;
                    if(mm[j] < 0){
                         flag = false;
                         break;
                    }
               }
               if(flag) ans += i.size();
         }
         return ans;
    }
};
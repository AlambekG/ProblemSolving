class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> mp;
        
        for(int i = 0;i < num.size();i ++) mp[num[i]] ++;
        for(int i = 0;i < num.size();i ++){
              int x = int(num[i] - 48);
              if(x != mp[char(i + 48)]) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> mp, mm;
        
        for(auto i : arr) mp[i] ++;
        
        for(int i = -1000;i <= 1000;i ++){
            if(mp[i] != 0){
                mm[mp[i]] ++;
                if(mm[mp[i]] > 1) return false;
            }
        }
        return true;
    }
};
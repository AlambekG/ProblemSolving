class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map <int, int> mp;
        for(auto i: nums) mp[i] ++;
        
        vector <int> v;
        for(int i = -100;i <= 100;i ++){
            if(mp[i]) v.push_back(i);
        }
        
        nums = v;
        return v.size();
    }
};  
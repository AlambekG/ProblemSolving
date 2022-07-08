class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         unordered_map <int, int> mp;
         for(auto i : nums) mp[i] ++;
         
         vector <int> ans;
         for(int i = 1;i <= nums.size();i ++)
            if(!mp[i]) ans.push_back(i);
         return ans;
    }
};
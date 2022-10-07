class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r = 0;
        bool ans = true;
        for(int i = 0;i < nums.size();i ++){
           if(i > r) {
               ans = false;
               break;
           }
           r = max(r, nums[i] + i); 
        }
        return ans;
    }
};
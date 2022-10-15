class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector <int> v;
        if(n < 3) return 0;
        
        int l = 0, cnt = 0, r = 0;
        
        int diff = nums[1] - nums[0], val = 0;
        for(int i = 2;i < n;i ++){
            if(nums[i] - nums[i - 1] == diff){
                r = i;
                continue;
            }
            else{
                v.push_back(r - l + 1);
                val = r - l + 1;
                if(val > 2) cnt += ((val - 2)*(val - 1) / 2);
                l = i - 1;
                diff = nums[i] - nums[i - 1];
            }
        }
        if(r != l){
            val = r - l + 1;
            if(val > 2) cnt += ((val - 2)*(val - 1) / 2);
        }
        return cnt;
    }
};
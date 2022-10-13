class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = 99999;
        for(auto i : prices){
             ans = max(ans, i - mn);
             mn = min(mn, i);
        }
        return ans;
    }
};
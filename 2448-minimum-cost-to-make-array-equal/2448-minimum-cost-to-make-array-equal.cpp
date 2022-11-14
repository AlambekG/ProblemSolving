class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector <pair <int, int> > v;
        
        for(int i = 0;i < nums.size();i ++){
            v.push_back(make_pair(nums[i], cost[i]));
        }
        sort(v.begin(), v.end());
        
        int n = nums.size();
        long long pp[n + 10], ss[n + 1], pref[n + 10], suf[n + 10];
        
        pp[0] = v[0].second;
        for(int i = 1;i < n;i ++){
            pp[i] = pp[i - 1] + v[i].second;
        }
        ss[n - 1] = v[n - 1].second;
        for(int i = n - 2;i >= 0;i --){
            ss[i] = ss[i + 1] + v[i].second;
        }
        
        pref[0] = 0;
        for(int i = 1;i < n;i ++){
            pref[i] = pp[i - 1] * (v[i].first - v[i - 1].first) + pref[i - 1];     
        }
        
        
        suf[n - 1] = 0;
        for(int i = n - 2;i >= 0;i --){
            suf[i] = ss[i + 1] * (v[i + 1].first - v[i].first) + suf[i + 1];
        }
        long long ans = suf[0];
        for(int i = 0;i < n;i ++){
            ans = min(ans, pref[i] + suf[i]);
        }
        return ans;
    }
};
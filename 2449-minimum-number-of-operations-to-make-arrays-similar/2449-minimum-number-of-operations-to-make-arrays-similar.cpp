class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        vector <long long> ev, od;
        for(int i = 0;i < nums.size();i ++){
            if(nums[i] % 2) od.push_back(nums[i]);
            else ev.push_back(nums[i]);
        }
        
        vector <long long> ev2, od2;
        for(int i = 0;i < nums.size();i ++){
            if(target[i] % 2) od2.push_back(target[i]);
            else ev2.push_back(target[i]);
        }
        
        long long s = 0, s2 = 0;
        for(int i = 0;i < ev.size();i ++){
            if(ev[i] > ev2[i]) s += (ev[i] - ev2[i]);
        }
        
        for(int i = 0;i < od.size();i ++){
            if(od[i] > od2[i]) s2 += (od[i] - od2[i]);
        }
        
        return s2 / 2 + s / 2;
    }
};
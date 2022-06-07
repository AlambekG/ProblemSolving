class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<bool> vis(n,false);
        vector<vector<int>> v;
        
        vector<int> dp(n , INT_MAX);
        
        vis[0] = true;
        dp[0] = 0;
        
        v.push_back({arr[0]});
        
        int res = 0;
        
        while(v.size() < n){
            
        for(int i=0;i<n;i++){
            int t = v.size();
            if(vis[i] == false) dp[i] = min(dp[i] , abs(arr[i][0] - v[t-1][0]) + abs(arr[i][1] - v[t-1][1]));
         }
              
        int id = -1;
        
        for(int k = 0; k<n; k++){
            if(vis[k] == false){
                if(id == -1 || dp[k] < dp[id]) id = k;
            }
        }
        
        vis[id] = true;
        res = res + dp[id];
        v.push_back({arr[id]});
    }
        
        return res;
        
    }
};
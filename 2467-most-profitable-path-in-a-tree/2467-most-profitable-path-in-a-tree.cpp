class Solution {
public:
    unordered_map <int, int> mp;
    vector <int> vec[110000];
    unordered_map <int, int> us, vis;
    unordered_map <int, int> path, par;
    
    
    int ans = -999999;
    
    void dfs(int v){
        us[v] = 1;
        for(auto i : vec[v]){
            if(!us[i]){
                par[i] = v;
                dfs(i);
            }
        }
    }
    
    void dfs2(int v, int sm, int cnt){
        bool flag = true;
        vis[v] = cnt;
        
        for(auto i: vec[v]){
            if(!vis[i]){
                flag = false;
                int val = 0;
                
                if(cnt + 1 == us[i]) val = mp[i] / 2;
                else if(us[i] && cnt + 1 > us[i]) val = 0;
                else val = mp[i];
                
                dfs2(i, sm + val, cnt + 1);
            }
        }
        
        if(flag) ans = max(ans, sm);
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(int i = 0;i < amount.size();i ++) mp[i] = amount[i];
        
        for(auto i : edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        dfs(bob);
        
        int cur = 0;
        vector <int> v;
        v.push_back(cur);
        while(cur != bob){
            cur = par[cur];
            v.push_back(cur);
        }
        cur = 1;
        
        for(int i = 0;i < amount.size();i ++) us[i] = 0;
        for(int i = v.size() - 1;i >= 0;i --){
            us[v[i]] = cur;
            cur ++;
        }
             
        dfs2(0, amount[0], 1);
        
        return ans;
    }
};
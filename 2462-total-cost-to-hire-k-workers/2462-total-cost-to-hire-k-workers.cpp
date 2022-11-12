class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        set <pair <int, int>> st;
        
        unordered_map <int, int> mp;
        for(int i = 0; i < candidates;i ++){
            st.insert(make_pair(costs[i], i));
            mp[i] = 1;
        }
        
        for(int i = costs.size() - candidates;i < costs.size();i ++){
            st.insert(make_pair(costs[i], i));
            mp[i] = 1;
        }
        int l = candidates - 1, r = costs.size() - candidates, cnt = 0;
    
        long long sm = 0;
        cout << l << 'x' << r << endl;
        
        while(cnt < k){
            auto cur = (*st.begin());
            st.erase(st.begin());
            //if(mp[cur.second]) continue;
            mp[cur.second] = 1;
            cnt ++;
            sm += cur.first;
            if(cur.second <= l) {
                
                if(l < costs.size() - 1 && l < r){
                    l ++;
                    st.insert(make_pair(costs[l], l));
                } 
            }
            else {
                
                if(r > 0 && r > l) {
                    r --;
                    st.insert(make_pair(costs[r], r));
                 }
            }
            
        }
        
        return sm;
    }
};
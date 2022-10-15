class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int> > ans;
        
        vector <int> vv;
        for(int i = 1;i <= numRows;i ++){
            vector <int> v;
            
            v.push_back(1);
            
            if(vv.size()){
                for(auto j : vv) v.push_back(j);
            }
            if(i > 1) v.push_back(1);
            vv.clear();
            
            for(int j = 1;j < v.size();j ++){
                 vv.push_back(v[j] + v[j - 1]);
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};
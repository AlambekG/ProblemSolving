class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> vv;
        
        vector <int> v;
        for(int i = 1;i <= rowIndex + 1;i ++){
            v.clear();
            v.push_back(1);
            
            if(vv.size()){
                for(auto j : vv) v.push_back(j);
            }
            if(i > 1) v.push_back(1);
            vv.clear();
            
            if(i != 34)
            for(int j = 1;j < v.size();j ++){
                 vv.push_back(v[j] + v[j - 1]);
            }    
        }
        return v;
    }
};
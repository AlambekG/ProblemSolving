class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string abc[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
                   "tuv", "wxyz"};
        
        vector <string> ans;
        for(auto i : digits){
            int ind = int(i - 48);
            vector <string> v = ans;
            ans.clear();
            
            if(v.empty()){
                 for(int j = 0;j < abc[ind].size();j ++)
                 {
                     string st = "";
                     st += abc[ind][j];
                     ans.push_back(st);
                 }
            }
            else{
                 for(auto j : abc[ind]){
                      for(auto k : v){
                            ans.push_back(k + j);
                      }
                 }
            }
        }
        return ans;
    }
};
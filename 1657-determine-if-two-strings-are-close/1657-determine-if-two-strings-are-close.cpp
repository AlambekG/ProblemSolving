class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        
             
        unordered_map<int, int> mp, mm;
             
        for(auto i : word1) mp[i] ++;
             
        for(auto i : word2){
            if(!mp[i]) return false;
            mm[i] ++;
        }
        
        vector <int> v1, v2;
        for(int i = 0;i < 27;i ++){
            char ch = char('a' + i);
            v1.push_back(mp[ch]);
            v2.push_back(mm[ch]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i = 0;i < v1.size();i ++)
             if(v1[i] != v2[i]) return false;
        return true;
    }
};
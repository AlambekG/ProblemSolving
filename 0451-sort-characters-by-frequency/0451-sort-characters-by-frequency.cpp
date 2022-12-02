class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> mp;
        string st = "";
        for(auto i : s) mp[i] ++;
        
        vector <pair <int, char> > vv;
        for(auto i : mp) {
           vv.push_back(make_pair(i.second, i.first));
        }
        sort(vv.rbegin(), vv.rend());
        for(auto i : vv){
            int cnt = i.first;
            while(cnt --)
                st += i.second;
        }
        return st;
    }
};
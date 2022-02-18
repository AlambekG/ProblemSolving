class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
           unordered_map <char, int> mp;
           for(auto i : words){
                  unordered_map <char, int> mm;
                  for(int j = 0;j < i.size();j ++){
                          mm[i[j]] ++;
                  }
                  if(mp.empty()) mp = mm;
                  else{
                     for(int j = 0;j < 26;j ++){
                           char ch = char(j + 'a');
                           mp[ch] = min(mp[ch], mm[ch]);
                     }
                  }
           }
          vector <string> v;
          for(int i = 0;i < 26;i++){
              char ch = char(i + 'a');
              while(mp[ch]){
                  string s;
                  s += ch;
                   v.push_back(s);
                  mp[ch] --;
              }
          }
        return v;
    }
};
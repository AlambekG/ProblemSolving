class Solution {
public:
    bool checkIfPangram(string sentence) {
         set <char> st;
         for(auto i : sentence)
              st.insert(i);
         return st.size() == 26;
    }
};
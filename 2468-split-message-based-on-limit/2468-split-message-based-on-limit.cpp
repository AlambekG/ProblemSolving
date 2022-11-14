class Solution {
public:
    
    string toStr (int x){
        string ss = "";
        while(x){
            ss = char(x % 10 + 48) + ss;
            x /= 10;
        }
        return ss;
    }
    
    int check(int r, string message, int limit){ 
        int l = 0;
        string ss = toStr(r);
        
        int j = 1;
        for(;j <= r;j ++){
            string s = toStr(j);
            s = s + "/"  + ss;
            s = "<" + s + ">";
            
            string str = "";
            while(str.size() + s.size() < limit && l < message.size()){
                str += message[l];
                l ++;
            }
            if(l >= message.size()) break;
            str += s;
        }
        if(l < message.size()) return 0;
        if(j <= r) return 1;
        return -1;
    }
    
    vector<string> splitMessage(string message, int limit) {
        
        vector <string> vec;
        
        int l = 0, r = message.size();
        while(l < r - 1){
            int mid = (l + r) >> 1;
            if(check(mid, message, limit) == 0) l = mid;
            else r = mid;
        }
        
        l = 0;
        string ss = toStr(r);
        
        for(int j = 1;j <= r;j ++){
            string s = toStr(j);
            s = s + "/"  + ss;
            s = "<" + s + ">";
            
            string str = "";
            while(str.size() + s.size() < limit && l < message.size()){
                str += message[l];
                l ++;
            }
            str += s;
            if(l == 0) return vec;
            vec.push_back(str);
        }
        vector <string> v;
        if(l < message.size()) return v;
        return vec;
    }
};
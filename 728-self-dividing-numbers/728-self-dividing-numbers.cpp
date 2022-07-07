class Solution {
public:
    bool ok(int x){
         int a = x;
        while(x > 0){
            if(x % 10 == 0 || a % (x % 10)) return false;
            x /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans;
         for(int i = left;i <= right;i ++) if(ok(i)) ans.push_back(i);
        return ans;
    }
};
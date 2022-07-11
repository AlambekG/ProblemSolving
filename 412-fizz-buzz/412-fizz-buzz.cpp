class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> v;
        for(int i = 1;i <= n;i ++){
            string s = "";
            
            if(i % 3 == 0 && i % 5 == 0){
                s = "FizzBuzz";
            }
            else if(i % 3 == 0){
                s = "Fizz";
            }
            else if(i % 5 == 0){
                s = "Buzz";
            }
            else{
                int x = i;
                while(x > 0){
                     s = char(x % 10 + 48) + s; 
                     x /= 10;
                }
            }
            v.push_back(s);
           }
           return v;
    }
};
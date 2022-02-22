class Solution {
public:
    string shortestPalindrome(string s) {
        string res,str;
        int i,j,c,r,l,mirror,n=s.length(),a,b,N,maxOmit;
        for(i=0;i<n;i++){ 
            str.push_back('#'); 
            str.push_back(s[i]);
        } 
        str.push_back('#');
        N=n;
        n=2*n+1; c=r=l=0; maxOmit=1;
        int P[n];
        for(i=0;i<n;i++) 
            P[i]=0;
        for(i=0;i<n;i++){
          mirror=2*c-i;
          if(i<r) 
           P[i]=min(r-i,P[mirror]);
          a=i+(P[i]+1); b=i-(P[i]+1);
          while(a<n&&b>=0&&str[a]==str[b]){
            P[i]++;
            a++; b--;
          }
          if((i+P[i])>r){
            c=i;
            r=i+P[i];
            l=i-P[i];
            if(l==0) 
                maxOmit=max(maxOmit,(r-l)/2);
          }
        }
        if(maxOmit==N) return s;
        for(i=N-1;i>=maxOmit;i--) 
            res.push_back(s[i]);
        res.append(s);
        return res;
    }
};
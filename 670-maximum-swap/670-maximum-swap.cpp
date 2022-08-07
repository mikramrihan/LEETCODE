class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int a=0,b=0,mxi=n-1;
        for(int i=n-2;i>=0;i--){
            if(s[mxi]<s[i]){
                mxi=i;
            }
            if(s[i]<s[mxi]){
                a=mxi;
                b=i;
            }
        }
        swap(s[a],s[b]);
        return stoi(s);
        
    }
};
class Solution {
public:
    bool isGoodArray(vector<int>& num) {
        int st=num[0];
        for(int i=0;i<num.size();i++)
        {
            st=__gcd(st,num[i]);
        }
        return st==1;
    }
};
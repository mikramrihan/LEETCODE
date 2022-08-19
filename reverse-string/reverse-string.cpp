class Solution {
public:
    void reverse(int l,int r,vector<char>&s){
        if(l>=r){
            return;
        }
        swap(s[l],s[r]);
        reverse(l+1,r-1,s);
        
    }
    void reverseString(vector<char>& s) {
        reverse(0,s.size()-1,s);
    }
};
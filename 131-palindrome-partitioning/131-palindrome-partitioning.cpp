class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool ispalin(string s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
    void solve(int i,int n,string s){
        if(i==n){
            ans.push_back(path);
        }
        else{
            for(int k=i;k<n;k++){
                if(ispalin(s,i,k)){
                    path.push_back(s.substr(i,k-i+1));
                    solve(k+1,n,s);
                    path.pop_back();
                    
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        
        solve(0,n,s);
        return ans;
    }
};
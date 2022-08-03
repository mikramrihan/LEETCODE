class Solution {
public:
    vector<int> dp;
    bool ispalindrom(int l,int r,string &s){
        while(l<=r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
    // int helper(int i,int n,string s){
    //     if(i==n){
    //         return dp[i]=0;
    //     }
    //     if(dp.find(i)!=dp.end()){
    //         return dp[i];
    //     }
    //     int ans=INT_MAX;
    //     for(int j=i;j<n;j++){
    //         if(dp1[i][j]){
    //             int cost=1+helper(j+1,n,s);
    //             ans=min(ans,cost);
    //         }
    //     }
    //     return dp[i]=ans;
    // }
    
    int minCut(string s) {
        int n=s.size();
        dp=vector<int>(n+1,0);
        vector<vector<int>> dp1(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrom(i,j,s)) dp1[i][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            int cost=INT_MAX;
            for(int j=i;j<n;j++){
                if(dp1[i][j]){
                    cost=min(cost,1+dp[j+1]);
                }
            }
            dp[i]=cost;
        }
        
        return dp[0]-1;
    }
};
// if you cant handle stress
// you cant handle success
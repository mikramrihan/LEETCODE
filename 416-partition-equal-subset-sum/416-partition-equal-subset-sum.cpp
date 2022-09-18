class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        int sm=0;
        for(auto c:a){
            sm+=c;
        }
        if(sm%2){
            return 0;
        }
        else{
            vector<vector<bool>> dp(n+1,vector<bool>((sm/2)+1,0));
            dp[0][0]=1;;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=(sm/2);j++){
                    if(a[i-1]<=j){
                        dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
//             for(auto i: dp){
//                 for(auto c: i){
//                     cout << c << " ";
//                 }
//                 cout << endl;
                
//             }
            return dp[n][sm/2];
        }
    }
};
class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(3,INT_MIN));
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            if(a[i]%3==0){
                dp[i+1][0]=max(dp[i][0],dp[i][0]+a[i]);
                dp[i+1][1]=max(dp[i][1],dp[i][1]+a[i]);
                dp[i+1][2]=max(dp[i][2],dp[i][2]+a[i]);
            }
            else if(a[i]%3==1){
                dp[i+1][0]=max(dp[i][0],dp[i][2]+a[i]);
                dp[i+1][1]=max(dp[i][1],dp[i][0]+a[i]);
                dp[i+1][2]=max(dp[i][2],dp[i][1]+a[i]);
            }
            else{
                dp[i+1][0]=max(dp[i][0],dp[i][1]+a[i]);
                dp[i+1][1]=max(dp[i][1],dp[i][2]+a[i]);
                dp[i+1][2]=max(dp[i][2],dp[i][0]+a[i]);
            }
        }
        return dp[n][0];
        
    }
};
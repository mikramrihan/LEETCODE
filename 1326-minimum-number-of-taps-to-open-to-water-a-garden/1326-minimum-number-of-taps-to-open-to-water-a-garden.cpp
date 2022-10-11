class Solution {
public:
    int minTaps(int n, vector<int>& a) {
        int dp[n+1];
        const int M=2e5;
        memset(dp,M,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=max(0,i-a[i]);j<=min(n,i+a[i]);j++){
                dp[j]=min(dp[j],dp[(max(0,i-a[i]))]+1);
            }   
        }
        return (dp[n]>=M?-1:dp[n]);
    }
};
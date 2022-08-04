class Solution {
public:
    int dp1[2005][10]; 
    int helper(int i,int n,vector<vector<int>>&dp , int count,int k){
        if(i==n){
            if(count==k){
                return dp1[i][count]=0;
            }
            return dp1[i][count]=INT_MAX/2;
        }
        if(count==k){
            return dp1[i][count]=(i==n?0:INT_MAX/2);
        }
        if(dp1[i][count]!=-1){
            return dp1[i][count];
        }
        int ans=INT_MAX/2;;
        for(int kk=i;kk<n;kk++){
            int cost=helper(kk+1,n,dp,count+1,k)+dp[i][kk];
            // cout << "{cost: "<<i<<" "<<kk<<" "<<count<<" "<<cost<<" }";
            ans=min(ans,cost);
        }
        // cout << endl;
        return dp1[i][count]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<2005;i++){
            for(int j=0;j<10;j++){
                dp1[i][j]=-1;
            }
        }
        // debug(dp1[5][5]);
        for(int i=0;i<n;i++){
            dp[i][i]=0;

        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 0;
            }
            else{
                dp[i][i+1]=1;
            }
        }
        // for(auto i : dp){
        //     debug(i);
        // }
        // cout << endl;
        for(int i=1 ;i<n;i++){
            int k=0;
            for(int j=i;j<n;j++){

                if(s[k]==s[j] ){
                    dp[k][j]=dp[k+1][j-1];
                }
                else{
                    dp[k][j]=1+dp[k+1][j-1];
                }
                k++;
                // debug(i,j,s[i]==s[j],dp[i+1][j-1],dp[i][j]);
            }

        }

        // debug(dp);
        // for(auto i : dp){
        //     debug(i);
        // }

        int solve=helper(0,n,dp,0,k);
        return solve;
    }
    bool checkPartitioning(string s) {
        return (palindromePartition(s,3)==0);
    }
};
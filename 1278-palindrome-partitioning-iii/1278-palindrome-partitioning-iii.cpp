class Solution {
public:
    int ispalindrom(int i,int j ,string&s){
        int cnt=0;
        while(i<=j){
            if(s[i++]!=s[j--]){
                cnt++;

            }
        }
        return cnt;
    }
    map<pair<int,int>,int> mp;
    int helper(int i,int n,vector<vector<int>>&dp , int count,int k){
        if(i==n){
            if(count==k){
                return 0;
            }
            return INT_MAX/2;
        }
        if(count==k){
            return (i==n?0:INT_MAX/2);
        }
        if(mp.find({i,count})!=mp.end()){
            return mp[{i,count}];
        }
        int ans=INT_MAX/2;;
        for(int kk=i;kk<n;kk++){
            int cost=helper(kk+1,n,dp,count+1,k)+dp[i][kk];
            // cout << "{cost: "<<i<<" "<<kk<<" "<<count<<" "<<cost<<" }";
            ans=min(ans,cost);
        }
        // cout << endl;
        return mp[{i,count}]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                dp[i][j]=ispalindrom(i,j,s);
                // cout << "{ " <<i<<" "<<j<<" "<<dp[i][j]<<" } ";


            }
            // cout << endl;
       }

        int solve=helper(0,n,dp,0,k);
        return solve;
    }
};
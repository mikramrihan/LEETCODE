#define set_bits __builtin_popcountll
class Solution {
public:
    string shortestSuperstring(vector<string>& a) {
        int n=a.size();
        vector<vector<int>> dist(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                for(int k=min(a[i].size(),a[j].size());k>0;k--){
                    if(a[i].substr(a[i].size()-k)==a[j].substr(0,k)){
                        dist[i][j]=k;
                        break;
                    }
                }
            }
        }

        vector<vector<string>> dp(1<<n,vector<string>(n));
        for(int i=0;i<n;i++){
            dp[1<<i][i]=a[i];
        }
        for(int mask=0;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    for(int j=0;j<n;j++){
                        if(i==j)continue;
                        if(mask&(1<<j)){
                            string newt=dp[mask^(1<<i)][j]+(a[i].substr(dist[j][i]));
                            if(dp[mask][i].empty()|| dp[mask][i].size()>newt.size()){
                                dp[mask][i]=newt;
                            }
                        }
                    }
                }
            }
        }
        int lst=(1<<n)-1;
        string ans=dp[lst][0];
        for(int i =1;i<n;i++){
            if(dp[lst][i].size()<ans.size()){
                ans=dp[lst][i];
            }
        }
        // cout << ans << endl;
        return ans;

    }
};
class Solution {
public:
    map<string,int> mp;
    map<int,int> dp;
    int helper(int i,int n,vector<string>&words){
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int ans=1;
        
        for(int k=0;k<words[i].size();k++){
            string t=words[i].substr(0,k)+words[i].substr(k+1);
            // cout << t <<" ";
            if(mp.find(t)!=mp.end()){
                ans=max(ans,1+helper(mp[t],n,words));
            }
        }
        return dp[i]=ans;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            mp[words[i]]=i;
        }
        for(int i=0;i<n;i++){
            ans=max(ans,helper(i,n,words));
            // cout << ans << endl;
        }
        return ans;
        
    }
};
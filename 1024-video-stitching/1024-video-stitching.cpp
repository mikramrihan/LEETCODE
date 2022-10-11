class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        const int M=2e5;
        sort(clips.begin(),clips.end());
        vector<int> dp(time+1,M);
        dp[0]=0;
        for(auto x: clips){
            // cout << "{"<<x[0] <<" "<<x[1]<<"}"<<endl;
            for(int j=max(0,x[0]);j<=min(time,x[1]);j++){
                // cout << j << " "<<dp[j]<<" "<<dp[max(0,x[0])]+1 << endl;
                dp[j]=min(dp[j],dp[max(0,x[0])]+1);
            }
            // cout << "DP"<< endl;
            // for(auto i: dp){
            //     cout << i << " ";
            // }
            // cout << "END"<<endl;
        }
        // for(auto i: dp){
        //     cout << i << " ";
        // }
        return (dp[time]>=M?-1:dp[time]);
    }
};
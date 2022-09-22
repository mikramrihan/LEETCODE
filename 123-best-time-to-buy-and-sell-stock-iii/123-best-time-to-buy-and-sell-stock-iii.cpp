class Solution {
public:
    
    int profit=0;
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //--***NO NEED OF BASE CASE bcs evrthing already assine by 0
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        profit=max((0+dp[ind+1][1][cap]),(dp[ind+1][0][cap]-prices[ind]));
                    }
                    else{
                        profit=max((0+dp[ind+1][0][cap]),(dp[ind+1][1][cap-1]+prices[ind]));
                    }
                     dp[ind][buy][cap]=profit;
                }
            }
        }
//         dp[i][j][k]=for n to ith element m no of transactions k hoge and j represent buy or not 
        
        return dp[0][1][2];
    }
};
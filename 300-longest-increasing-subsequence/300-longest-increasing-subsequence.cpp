class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(auto i: nums){
            auto it=lower_bound(dp.begin(),dp.end(),i)-dp.begin();
            if(it==dp.size()){
                dp.push_back(i);
            }
            else{
                dp[it]=i;
            }
        }
        return dp.size();
        
    }
};
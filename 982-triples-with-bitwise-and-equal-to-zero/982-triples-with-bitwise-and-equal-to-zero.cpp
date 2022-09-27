class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto i: nums){
            for(auto j : nums){
                mp[(i&j)]++;
            }
        }
        for(auto i: nums){
            for(auto c: mp){
                if(!(i&c.first)){
                    ans+=c.second;
                }
            }
        }
        return ans;
    }
};
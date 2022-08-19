class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>> p;
        for(auto [x,y]:mp){
            p.push_back({y,x});
        }
        sort(p.begin(),p.end());
        vector<int> ans;
        for(int i=p.size()-1;i>=0;i--){
            ans.push_back(p[i].second);
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
    }
};
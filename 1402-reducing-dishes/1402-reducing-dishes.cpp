class Solution {
public:
    map<pair<int,int>,int> mp;
    int helper(int i,int n,int time ,vector<int>&sf)
    {
        if(i==n){
            return 0;
        }
        if(mp.find({i,time})!=mp.end()){
            return mp[{i,time}];
        }
        int ans=max(time*sf[i]+helper(i+1,n,time+1,sf),helper(i+1,n,time,sf));
        return mp[{i,time}]=ans;
    }
    int maxSatisfaction(vector<int>& sf) {
        int n=sf.size();
        int ans=0;
        sort(sf.begin(),sf.end());
        
        ans=max(ans,helper(0,n,1,sf));
        return ans;
        
        
    }
};
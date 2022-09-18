class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<pair<int,int>> p;
        for(auto i: in){
            p.push_back({i[0],i[1]});
        }
        int n=p.size();
        sort(p.begin(),p.end());
        vector<vector<int>> ans;
        
        auto save=p[0];
        bool f=0;
        for(int i=1;i<n;i++)
        {
            if(p[i].first<=save.second){
                save.second=max(save.second,p[i].second);
            }
            else{
                ans.push_back({save.first,save.second});
                save=p[i];
            }
        }
        ans.push_back({save.first,save.second});
        // cout << save.first << " "<<save.second;
        // cout << level.first<<" "<<level.second;
        // if(f==0)
        // ans.push_back({save.first,level.second});
        return ans;
        
    }
};
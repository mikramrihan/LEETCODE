class Solution {
public:
    string bestHand(vector<int>& v, vector<char>& suits) {
        int n=v.size();
        map<int,int> m;
        for(auto i:v)
        {
            m[i]++;
        }
        string ans = "High Card" ;
        if(equal(suits.begin()+1,suits.end(),suits.begin())) /// check same or not
        {
            ans="Flush";
            return ans;
        }
        for(auto i:m)
        {
            cout <<i.first<<" "<<i.second<<endl;
        }
        for(auto i:m)
        {
            // cout <<i.first<<" "<<i.second<<endl;
            if(i.second>=3)
            {
                ans="Three of a Kind";
                // return ans;
                break;
            }
            else if(i.second==2)
            {
                ans="Pair";
                // return ans;
                // break;
            }
        }
        return ans;
        
    }
};
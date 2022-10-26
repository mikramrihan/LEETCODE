class Solution {
public:
    #define FF first
    #define SS second
vector<int> start;
vector<int> endd;
vector<int> profit;
vector<vector<int>> p;
vector<int> dp; 

bool myComp(vector<int>& v1, vector<int>& v2) {
    if (v1[0] != v2[0]) {
        return v1[0] < v2[0];
    } else if (v1[1] != v2[1]) {
        return v1[1] < v2[1];
    }
    else if(v1[2]!= v2[2]){
        return v1[2]>v2[2];
    }
    return true;
}

int helper(int i,int n){
	// cout << i << endl;
	if(i>=n){
		return 0;
	}
    if(dp[i]!= -1){
        return dp[i];
    }
	auto c = lower_bound(start.begin(),start.end(),endd[i])-start.begin();
	// cout << "C : "<<c+1000 << profit[i] << " " << c << endl;
	int ans=profit[i]+helper(c,n);
	ans=max(ans,helper(i+1,n));
	return dp[i]=ans;
	
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profitt) {
        int n=startTime.size();
        for(int i=0;i<n;i++){
            p.push_back({startTime[i],endTime[i],profitt[i]});
        }
        sort(p.begin(),p.end());
        
        for(int i=0;i<n;i++){
            start.push_back(p[i][0]);
            endd.push_back(p[i][1]);
            profit.push_back(p[i][2]);
        }
       
        dp.resize(n);
        fill(dp.begin(),dp.end(),-1);


        int ans=helper(0,n);
        return ans;
    }
};

// 5
// 1 2 3 4 6
// 3 5 10 6 9
// 20 20 100 70 60 
    
// 4
// 1 2 3 3
// 3 4 5 6 
// 50 10 40 70  
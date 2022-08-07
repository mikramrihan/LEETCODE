class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int left=n-k;
        vector<int> s;
        for(int i=0;i<n;i++){
            while(s.size() && nums[i]<s.back() && left){
                s.pop_back();
                left--;
            }
            s.push_back(nums[i]);
        }
        vector<int> ans(s.begin(),s.begin()+k);
        return ans;
    }
};
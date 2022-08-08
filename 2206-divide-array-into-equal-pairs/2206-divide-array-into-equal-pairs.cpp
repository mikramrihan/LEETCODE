class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(505,0);
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        int pair=0;
        for(int i=0;i<505;i++){
            pair+=cnt[i]/2;
        }
        cout << pair << endl;
        int size=n/2;
        return pair==size;
        
    }
};
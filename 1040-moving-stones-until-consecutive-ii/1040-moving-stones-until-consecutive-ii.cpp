class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tot=0;
        int n=nums.size();
        int l=INT_MAX;
        for(int i=0,j=0;j<n;j++){
            while(nums[j]-nums[i]+1>n){
                i++;
            }
            int ran=j-i+1;
            if(ran==n-1 && nums[j]-nums[i]+1==n-1){
                l=min(l,2);
            }
            else{
                l=min(l,n-ran);
            }
        }
        return {l,max(nums[n-1]-nums[1]-n+2,nums[n-2]-nums[0]-n+2) };
    }
};
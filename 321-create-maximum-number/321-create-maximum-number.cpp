class Solution {
public:
    vector<int> fun(vector<int>& nums, int k) {
        int n=nums.size();
        int left=k;
        vector<int> s;
        
        for(int i=0;i<n;i++){
            if(!s.size()) {s.push_back(nums[i]);left--;continue;}
            int av=n-i;
            while(s.size() && nums[i]>s.back() && left<k && left<av){
                s.pop_back();
                left++;
            }
            s.push_back(nums[i]);
            left--;
        }
        vector<int> ans(s.begin(),s.begin()+(min((int)s.size(),k)));
        return ans;
    }
    void merge(vector<int>&a,vector<int>&b,vector<int>&res){
        int i=0;int j=0;int k=0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                int ti = i, tj = j;
                while(ti<a.size() and tj<b.size() and a[ti]==b[tj]) ti++, tj++;

                if(tj==b.size()) res.push_back(a[i]), i++;
                else
                if(ti<a.size() and a[ti]>b[tj]) res.push_back(a[i]), i++;
                else res.push_back(b[j]), j++;
            }
            else
            if(a[i]>b[j]) res.push_back(a[i]), i++;
            else res.push_back(b[j]), j++;
        }
        while(i<a.size()) res.push_back(a[i]), i++;
        while(j<b.size()) res.push_back(b[j]), j++;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<int> ans;
        for(int i=0;i<=k;i++){
            vector<int> st=fun(nums1,i);
            vector<int> tt=fun(nums2,k-i);
            vector<int> n;
            merge(st,tt,n);
            if(n.size()==k){
                ans=max(n,ans);
            }
            
        }
        return ans;
    }
    
};
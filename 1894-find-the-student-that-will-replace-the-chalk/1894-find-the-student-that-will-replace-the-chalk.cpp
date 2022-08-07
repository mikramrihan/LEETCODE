class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> pref(chalk.size());
        for(int i=0;i<chalk.size();i++){
            if(i==0){
                pref[i]=chalk[i];
            }
            else{
                pref[i]=chalk[i]+pref[i-1];
            }
        }
        k%=pref.back();
        auto it=upper_bound(pref.begin(),pref.end(),k)-pref.begin();
        return it;
        
    }
};
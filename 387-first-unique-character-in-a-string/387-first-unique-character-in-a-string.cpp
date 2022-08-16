class Solution {
public:
    int firstUniqChar(string s) {
        int mp[26];
        memset(mp,0,sizeof(mp));
        for(auto i: s){
            mp[i-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']<2){
                return i;
            }
        }
        return -1;
        
    }
};
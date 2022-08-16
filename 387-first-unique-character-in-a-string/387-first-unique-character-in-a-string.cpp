class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto i: s){
            mp[i]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]<2){
                return i;
            }
        }
        return -1;
        
    }
};
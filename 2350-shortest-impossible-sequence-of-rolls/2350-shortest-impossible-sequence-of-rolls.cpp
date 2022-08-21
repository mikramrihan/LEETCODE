class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size();
        unordered_map<int,int> mp;
        int level=1;
        for(int i=0;i<n;i++){
            mp[rolls[i]]++;
            if(mp.size()==k){
                level++;
                mp.clear();
            }
        }
        return level;
    }
};
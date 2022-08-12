class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> x={a,b,c};
        sort(x.begin(),x.end());
        if(x[2]-x[0]==2){
            return {0,0};
        }
        else{
            int l=min(x[2]-x[1] ,x[1]-x[0]);
            if(l<=2){
                l=1;
            }
            else{
                l=2;
            }
            return {l,x[2]-x[0]-2};
        }
    }
};
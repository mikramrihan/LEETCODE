class Solution {
public:
//     ll solve(int i,int j){
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(i==0){
//             dp[i][j]=
//         }
//         else{
            
//         }
//         return dp[i][j];
//     }
    int minimumOneBitOperations(int n) {
        vector<int> left(31,0);
        left[0]=1;
        left[1]=3;
        // left[2]=;
        for(int i=2;i<31;i++){
            left[i]=left[i-1]<<1;
        }
        // debug(left);
        int ans=0;
        // 0 0 0 1 1 0 
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                ans+=(1<<i);
                n^=left[i];
            }
        }
        return ans;
    }
};
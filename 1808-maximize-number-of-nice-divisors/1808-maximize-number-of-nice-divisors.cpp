class Solution {
public:
    long long pow(long long int x,int y){
        long long res=1;
        int MOD=1e9+7;

        while(y){
            if(y&1){
                res*=x;
                res%=MOD;
            }
            y>>=1;
            x=((x*x)%MOD);
        }
        return res%MOD;
    }
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<=3){
            return primeFactors;
        }
        int ans=primeFactors/3;
        int rem=primeFactors%3;
        if(rem==1){
            rem=4;
            --ans;
        }
        if(!rem){
            rem=1;
        }
        const int NN=1e9+7;
        return ((pow((int)3,ans)*rem)%NN);
    }
    
};
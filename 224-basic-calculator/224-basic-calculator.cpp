class Solution {
public:
    int cal(string &s, int &j)
    {
        int sum =0;
        char ch = '+';
        int tmp = 0;
        while(j<s.length())
        {
            while(j<s.length() && s[j]!='(' && s[j]!=')')
            {
                if(s[j]>='0' && s[j]<='9')
                {
                    tmp = tmp*10 + (s[j]-'0');
                    
                }else if(s[j] != ' ')
                {
                    if(ch == '+')
                        sum+=tmp;
                    else
                        sum-=tmp;
                    
                    ch = s[j];
                    tmp =0;
                }
                j++;
            }
            
            if(ch == '+')
                sum+=tmp;
            else
                sum-=tmp;
            
            if(j<s.length())
            {
                if(s[j]==')')
                {
                    j++;
                    return sum;
                }
                
                else if(ch == '+')
                        sum+=cal(s,++j);
                else
                        sum-=cal(s,++j);
            }
        }
        return sum;
    }
    int calculate(string &s) {
        int  j =0;
        int sum =0;
        
        while(j<s.length())
        {
            sum+=cal(s,j);
        }
        
        return sum;
    }
};
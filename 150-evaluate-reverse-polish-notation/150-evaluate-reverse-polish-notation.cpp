class Solution {
public:
    int evalRPN(vector<string>& st) {
        int n=st.size();
        stack<int64_t> s;
        for(int i=0;i<n;i++){
            if(st[i]=="+"){
                int l=s.top();
                s.pop();
                l+=s.top();
                s.pop();
                s.push(l);
            }
            else if(st[i]=="-"){
                int l=s.top();
                s.pop();
                int m=s.top();
                s.pop();
                s.push(m-l);
            }
            else if(st[i]=="/"){
                int l=s.top();
                s.pop();
                int m=s.top();
                s.pop();
                s.push(m/l);
            }
            else if(st[i]=="*"){
                int64_t l=s.top();
                s.pop();
                int64_t m=s.top();
                s.pop();
                s.push(l*m);
            }
            else{
                s.push(stoi(st[i]));
            }
        }
        return s.top();
    }
};
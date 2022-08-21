class Solution {
public:
    vector<vector<int>> vis;
    bool ans=0;
    int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
    bool check(int i,int j,int n,int m){
        if(i<0|| j<0 || i==n || j==m){
            return 0;
        }
        return 1;
        
    }
    void helper(int i,int j,int k,int n,int m,int t,vector<vector<char>>&ab,string& word){
        
        if(k==t){
            // cout << ab[i][j]<<endl;
            ans=1;
            return;
        }
        
        if(ab[i][j]!=word[k] || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        // cout << "{ "<<ab[/i][j]<< " "<<word[k]<<" } "; 
        for(int idi=0;idi<4;idi++){

            int l=d4i[idi]+i;
            int r=d4j[idi]+j;
            if(check(l,r,n,m)){
                // cout << l<<" : "<<r<<endl;
                helper(l,r,k+1,n,m,t,ab,word);
            }

        }    
        vis[i][j]=0;
    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int t=word.size();
        int i=-1;
        int j=-1;
        bool f=0;
        
        vector<pair<int,int>> p;
        for(int ii=0;ii<n;ii++){
            for(int jj=0;jj<m;jj++){
                if(board[ii][jj]==word[0]){
                    f=1;
                    p.push_back({ii,jj});
                    
                }
                
            }
        }
        if(!f){
            return 0;
        }
        if(n==1 && m==1 && t==1){
            if(board[0][0]==word[0]){
                return 1;
            }
            else{
                return 0;
            }
        }
        for(auto i: p){
            // cout << i.first <<" "<<i.second << endl;
            vis=vector<vector<int>>(n,vector<int>(m,0));
            helper(i.first,i.second,0,n,m,t,board,word);
        }
        return ans;
    }
};
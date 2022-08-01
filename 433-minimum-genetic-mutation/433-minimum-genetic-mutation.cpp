class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> validGene(bank.begin(),bank.end());
        
        if(!validGene.count(end)) return -1;
        
        vector<char> choices = {'A','C','G','T'};
        
        queue<string> bfs;
        unordered_set<string> visited;
        string current, s1;
        char eachCurrent;
        bfs.push(start);
        visited.insert(start);
        int mutations=0, size=0;
        while(!bfs.empty()){
            
            size=bfs.size();
            while(size--){
                current=bfs.front();
                bfs.pop();
                
                if(current==end) return mutations;
                
                for(int i=0;i<current.length();++i){
                    eachCurrent=current[i];
                    
                    for(auto j:choices){
                        s1=current;
                        s1[i]=j;
                        if(s1!=current && !visited.count(s1) && validGene.count(s1)){
                            bfs.push(s1);
                            visited.insert(s1);
                        }
                    }
                }
            }
            mutations++;
        }
        return -1;
    }
};
class Solution {
public:
    int ladderLength(string start, string endWord, vector<string>& wordList) {
        unordered_set<string> validGene(wordList.begin(),wordList.end());
        
        if(!validGene.count(endWord)) return 0;
        
        vector<char> choices = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        
        queue<string> bfs;
        unordered_set<string> visited;
        string current, s1;
        char eachCurrent;
        bfs.push(start);
        visited.insert(start);
        int mutations=1, size=0;
        while(!bfs.empty()){
            
            size=bfs.size();
            while(size--){
                current=bfs.front();
                bfs.pop();
                
                if(current==endWord) return mutations;
                
                for(int i=0;i<current.length();++i){
                    eachCurrent=current[i];
                    
                    for(auto j:choices){
                        s1=current;
                        s1[i]=j;
                        // cout << s1<<endl;
                        if(s1!=current && !visited.count(s1) && validGene.count(s1)){
                            bfs.push(s1);
                            visited.insert(s1);
                        }
                    }
                }
            }
            // for(auto i: visited){
            //     cout << i << " ";
            // }
            mutations++;
        }
        return 0;
    }
};
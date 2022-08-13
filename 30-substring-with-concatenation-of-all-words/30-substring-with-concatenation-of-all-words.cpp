class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length(), n = words.size(), m = s.length();
        multiset<string> db;
        vector<int> results;
        
        for(auto& word : words) {
            db.insert(word);
        }
        
        auto temp = db;
        for(int i = 0; i < m - n * len + 1; i += 1) {
            string word = s.substr(i, len);
            auto it = temp.find(word);
            
            if(it != temp.end()) {
                temp.erase(it);
                int j = i + len;
                
                while(j < m) {
                    word = s.substr(j, len);
                    it = temp.find(word);
                    
                    if(it != temp.end()) {
                        temp.erase(it);
                    }
                    else {
                        break;
                    }
                    
                    j += len;
                }
                
                if(temp.empty()) {
                    results.push_back(i);
                }
                
                temp = db;
            }
        }
        
        return results;
    }
};
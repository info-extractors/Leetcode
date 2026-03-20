class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){

            auto [word,level] = q.front();q.pop();
            if (word == endWord) return level;
            
            for(int i = 0;i < word.size();i++){
                char curr_char = word[i];
                for(char c = 'a';c <= 'z';c++){
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end()){
                        q.push({word,level + 1});
                        wordSet.erase(word);
                    }
                }
                word[i] = curr_char;
            }
        }

        return 0;
    }
};
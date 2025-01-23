class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<string> wordSet;

        // strore wordList in a set
        for(string st: wordList) wordSet.insert(st);

        std::queue<std::pair<std::string,int>> wordQueue;
        // int len = beginWord.size();

        int steps = 1;

        wordQueue.push({beginWord, steps});

        while(!wordQueue.empty()){
            auto [currWord, steps] = wordQueue.front();
            wordQueue.pop();

            if(currWord == endWord) return steps;

            for(int i=0; i<currWord.size();i++){
                char tmp = currWord[i];
                for(char j = 'a'; j <= 'z'; j++){
                    currWord[i] = j;
                    if(wordSet.find(currWord) != wordSet.end()){
                        wordQueue.push({currWord, steps+1});
                        wordSet.erase(currWord);
                    }
                }
                currWord[i] = tmp;
            }
        }
        return 0;
    }
};
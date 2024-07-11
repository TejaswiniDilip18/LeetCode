class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string::iterator ptr1;
        string::iterator ptr2;
        
        ptr1 = word1.begin();
        ptr2 = word2.begin();

        string merged_str;

        while(ptr1 != word1.end() && ptr2 != word2.end()){
            merged_str.push_back(*ptr1++);
            merged_str.push_back(*ptr2++);
            // ptr1++;
            // ptr2++;
        }

        while(ptr1 != word1.end()){
            // merged_str.push_back(word2.substr(word1.length()-1, word2.length()-word1.length()));
            merged_str.push_back(*ptr1++);
        }
        while(ptr2 != word2.end()){
            // merged_str.push_back(word1.substr(word2.length()-1, word1.length()-word2.length()));
            merged_str.push_back(*ptr2++);
        }

        return merged_str;
    }
};
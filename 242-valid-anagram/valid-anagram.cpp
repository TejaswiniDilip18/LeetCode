class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        // sort(s.begin(),s.end()); // O(nlogn)
        // sort(t.begin(), t.end());

        // for(int i=0; i<s.size(); i++){       // O(n)
        //     if(s[i] != t[i]) return false;
        // }
        // return true;

        vector<int> freq(26, 0); // frequency of letters a-z

        for(int i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int count: freq){
            if(count != 0) return false;
        }

        return true;
    }
};
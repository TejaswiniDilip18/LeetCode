class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> s1_map(26, 0);
        vector<int> s2_map(26, 0);

        for(char ch: s1){
            s1_map[ch -'a']++;
        }
        // initialize first window
        for(int i=0; i<s1.length(); i++){
            s2_map[s2[i] - 'a']++;
        }

        if(s1_map == s2_map) return true;

        // slide the window-> add new char, remove old char
        for(int i=s1.length(); i < s2.length(); i++){
            s2_map[s2[i] - 'a']++; // add new char
            s2_map[s2[i - s1.length()] - 'a']--; // remove old char

            if(s1_map == s2_map) return true;
        }

        return false;       
    }
};
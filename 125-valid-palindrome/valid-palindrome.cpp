class Solution {
public:
    bool isPalindrome(string s) {
        string s_new;
        
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
        return std::isspace(c) || !std::isalpha(c) && !std::isdigit(c) ;}), s.end());

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::tolower(c);});

        s_new = s;
        reverse(s_new.begin(), s_new.end());

        if(s == s_new) return true;
        else return false;

    }
};
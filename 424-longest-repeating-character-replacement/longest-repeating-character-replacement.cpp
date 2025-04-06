class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash_map[26];
        int left = 0, right = 0;
        int max_len = 0, max_freq = 0;

        while (right < s.length()) {
            hash_map[s[right] - 'A']++;
            max_freq = max(max_freq, hash_map[s[right] - 'A']);

            if ((right - left + 1) - max_freq <= k) {
                max_len = max(max_len, (right - left + 1));
            } else {
                hash_map[s[left] - 'A']--;
                left++;
            }

            right++;
        }

        return max_len;
    }
};
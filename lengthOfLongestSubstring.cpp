/*  Using hash instead of array, making the runtime slower  */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charMap;
        int maxLen = 0;
        int cLen = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (charMap.find(c) != charMap.end()) cLen = min(cLen, i-charMap[c]-1);
            cLen++;
            charMap[c] = i;
            maxLen = max(maxLen, cLen);
        }
        return maxLen;
    }
};

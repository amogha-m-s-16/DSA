class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        
        vector<int> lastInd(128, -1);

        for(int i = 0; i < s.size(); i++) {
            left = max(left, lastInd[s[i]] + 1);
            maxLength = max(maxLength, i - left + 1);
            lastInd[s[i]] = i;
        }
        return maxLength;
    }
};
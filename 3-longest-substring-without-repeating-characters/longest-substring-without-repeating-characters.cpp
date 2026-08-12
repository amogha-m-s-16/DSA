class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> mpp;
        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            if(mpp.find(c) != mpp.end() && mpp[c] >= left) left = mpp[c] + 1;

            maxLength = max(maxLength, right - left + 1);
            mpp[c] = right;
        }
        return maxLength;
    }
};
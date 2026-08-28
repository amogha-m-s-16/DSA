class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = INT_MIN;
        for(char ch: s) {
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};
class Solution {
private: 
    int helper(const string& s, int i, long long num, int sign) {
        if(s.size() <= i || !(isdigit(s[i]))) return (int) (sign * num);
        const int INT_MAX_VAL = INT_MAX;
        const int INT_MIN_VAL = INT_MIN;
        num = num * 10 + (s[i] - '0');

        if((sign * num) >= INT_MAX_VAL) return INT_MAX_VAL;
        if((sign * num) <= INT_MIN_VAL) return INT_MIN_VAL;

        return helper(s, i + 1, num, sign);
    }
public:
    int myAtoi(string s) {
        int i = 0;

        while(i < s.size() && s[i] == ' ') i++;

        int sign = 1;
        if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};
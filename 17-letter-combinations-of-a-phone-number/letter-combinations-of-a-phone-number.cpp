class Solution {
private:
    void getCombo(int ind, string digits, vector<string>& ans, string s, string combos[]) {
        if(ind == digits.size()) {
            ans.push_back(s);
            return;
        }

        int dig = digits[ind] - '0';

        for(int i = 0; i < combos[dig].size(); i++) {
            getCombo(ind + 1, digits, ans, s + combos[dig][i], combos);
        } 
    }
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        getCombo(0, digits, ans, s, combos);
        return ans;
    }
};
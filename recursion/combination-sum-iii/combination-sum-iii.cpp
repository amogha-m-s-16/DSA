class Solution {
private:
    void findCombinations(int sum, int last, int k, vector<int>& ds, vector<vector<int>>& ans) {
        if(sum == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        if(sum <= 0 || ds.size() > k) return;

        for(int i = last; i <= 9; i++) {
            if(i <= sum) {
                ds.push_back(i);
                findCombinations(sum - i, i + 1, k, ds, ans);
                ds.pop_back();
            }
            else break;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(n, 1, k, ds, ans);
        return ans;
    }
};
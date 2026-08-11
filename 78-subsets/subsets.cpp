class Solution {
private:
    void createSubset(int ind, vector<int>& a, vector<vector<int>>& ans, vector<int>& sub) {
        if(ind == a.size()) {
            ans.push_back(sub);
            return;
        }

        sub.push_back(a[ind]);
        createSubset(ind + 1, a, ans, sub);

        sub.pop_back();
        createSubset(ind + 1, a, ans, sub);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        createSubset(0, nums, ans, sub);
        return ans;
    }
};
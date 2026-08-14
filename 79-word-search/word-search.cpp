class Solution {
private:
    bool dfs(vector<vector<char>>& arr, string& word, int i, int j, int ind) {
        if(ind == word.length()) return true;

        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] != word[ind]) return false;

        char temp = arr[i][j];
        arr[i][j] = '#';

        bool found = dfs(arr, word, i + 1, j, ind + 1) ||
                     dfs(arr, word, i - 1, j, ind + 1) ||
                     dfs(arr, word, i, j + 1, ind + 1) ||
                     dfs(arr, word, i, j - 1, ind + 1);

        arr[i][j] = temp;

        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board[0].size();
        int n = board.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
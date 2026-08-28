class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isPossible(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool isPossible(vector<vector<char>>& a, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(a[i][col] == c) return false;
            if(a[row][i] == c) return false;

            if(a[3 * (row / 3) + i/ 3][3 * (col / 3) + i % 3] == c) return false;
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
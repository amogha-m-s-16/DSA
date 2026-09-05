class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxInd = (i / 3) * 3 + (j / 3);

                    if(rows[i][num] || cols[j][num] || boxes[boxInd][num]) return false;

                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[boxInd][num] = true;
                }
            }
        }

        return true;
    }
};
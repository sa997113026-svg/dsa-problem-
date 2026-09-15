class Solution {
public:

    bool issafe(vector<string>& board, int row, int col, int n) {

        // horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nqueen(vector<string>& board, vector<vector<string>>& ans,
                int n, int row) {

        // base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // try every column
        for (int j = 0; j < n; j++) {

            if (issafe(board, row, j, n)) {

                board[row][j] = 'Q';

                nqueen(board, ans, n, row + 1);

                // backtracking
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        nqueen(board, ans, n, 0);

        return ans;
    }
};
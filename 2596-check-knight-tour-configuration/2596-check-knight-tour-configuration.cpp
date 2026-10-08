class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expValue) {
        
        // Check boundaries and expected value
        if (r < 0 || c < 0 || r >= n || c >= n ||
            grid[r][c] != expValue) {
            return false;
        }

        // Reached the last value
        if (expValue == n * n - 1) {
            return true;
        }

        // All 8 possible knight moves
        int ans1 = isValid(grid, r - 2, c + 1, n, expValue + 1);
        int ans2 = isValid(grid, r - 2, c - 1, n, expValue + 1);
        int ans3 = isValid(grid, r + 2, c + 1, n, expValue + 1);
        int ans4 = isValid(grid, r + 2, c - 1, n, expValue + 1);
        int ans5 = isValid(grid, r + 1, c - 2, n, expValue + 1);
        int ans6 = isValid(grid, r + 1, c + 2, n, expValue + 1);
        int ans7 = isValid(grid, r - 1, c - 2, n, expValue + 1);
        int ans8 = isValid(grid, r - 1, c + 2, n, expValue + 1);

        return ans1 || ans2 || ans3 || ans4 ||
               ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Knight tour must start from 0
        if (grid[0][0] != 0) {
            return false;
        }

        return isValid(grid, 0, 0, n, 0);
    }
};
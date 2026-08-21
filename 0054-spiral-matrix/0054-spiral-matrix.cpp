class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // Top row
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // Right column
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // Bottom row
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(mat[erow][j]);
                }
            }

            // Left column
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    ans.push_back(mat[i][scol]);
                }
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
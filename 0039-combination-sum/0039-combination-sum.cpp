class Solution {
public:
    set<vector<int>> s;

    void getallcombinations(
        vector<int>& arr,
        int idx,
        int tar,
        vector<vector<int>>& ans,
        vector<int>& combin
    ) {
        if (idx == arr.size() || tar < 0) {
            return;
        }

        if (tar == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // Choose current element
        combin.push_back(arr[idx]);

        // Single use
        getallcombinations(arr, idx + 1, tar - arr[idx], ans, combin);

        // Multiple use
        getallcombinations(arr, idx, tar - arr[idx], ans, combin);

        combin.pop_back();

        // Don't choose current element
        getallcombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;

        getallcombinations(arr, 0, tar, ans, combin);

        return ans;
    }
};
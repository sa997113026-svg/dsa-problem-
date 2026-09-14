class Solution {
public:
    void getsubsets(vector<int>& nums, vector<int>& ans, int i,
                    vector<vector<int>>& allsubset) {

        if (i == nums.size()) {
            allsubset.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getsubsets(nums, ans, i + 1, allsubset);

        // Exclude
        ans.pop_back();

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
            idx++;

        getsubsets(nums, ans, idx, allsubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubset;
        vector<int> ans;

        getsubsets(nums, ans, 0, allsubset);

        return allsubset;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0; // Added count variable
        
        // 1. Build prefix sum array
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++) { // Started at i = 1 to prevent i-1 out of bounds
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        unordered_map<int, int> m; 
        
        // 2. Count subarrays
        for(int j = 0; j < n; j++) { // Started at j = 0
            if(prefixSum[j] == k) {
                count++;
            }
            
            int val = prefixSum[j] - k; // Fixed typo and variable scope
            if(m.find(val) != m.end()){
                count += m[val];
            }
            
            // Just increment the map, don't reset it to 0
            m[prefixSum[j]]++;
        }
        
        return count;
    }
};
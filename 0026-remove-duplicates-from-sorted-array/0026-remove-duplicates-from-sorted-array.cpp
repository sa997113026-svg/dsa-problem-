class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Handle edge case where the array is empty
        if (nums.empty()) return 0;
        
        // 'k' tracks the position for the next unique element
        // Since the first element is always unique, we start 'k' at 1
        int k = 1; 
        
        // Start scanning from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If we find a new unique element...
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // ...place it at the 'k' index
                k++;               // ...and move 'k' forward
            }
        }
        
        // k is now the count of unique elements
        return k; 
    }
};
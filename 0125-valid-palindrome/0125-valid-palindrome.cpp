class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.size() - 1;
        
        while (st < end) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[st])) {
                st++;
                continue;
            }
            
            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            
            // Compare the characters (ignoring case)
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            
            // Move both pointers inward
            st++;
            end--;
        }
        
        return true;
    }
};
        
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {

            // Find next valid character in s
            int skipS = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } 
                else if (skipS > 0) {
                    skipS--;
                    i--;
                } 
                else {
                    break;
                }
            }

            // Find next valid character in t
            int skipT = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } 
                else if (skipT > 0) {
                    skipT--;
                    j--;
                } 
                else {
                    break;
                }
            }

            // Compare current valid characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            }
            // One string has a valid character while the other doesn't
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> np = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans =0;

        for(int i=0; i<s.size(); i++){
            if(i+1 < s.size() && np[s[i]]< np[s[i+1]])
            {
                ans -= np[s[i]];
            }
            else
            {
                ans += np[s[i]];
            }
        }

        return ans;


    }
};
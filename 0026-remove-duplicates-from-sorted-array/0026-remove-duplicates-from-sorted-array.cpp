class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = 0;
        int unique = 1;
        int check = 1;
        while(check < nums.size())
        {
            if(nums[check] == nums[check-1])
            {
                check++;
                continue;
            }
            nums[flag+1] = nums[check];
            flag++;
            check++;
            unique++;
        }
        return unique;
    }
};
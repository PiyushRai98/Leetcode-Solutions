class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int answer = abs(nums[0]);

        for (int i = 1; i < nums.size(); i++){
            int x = nums[i];

            maxSum = max(x, maxSum + x);

            minSum = min(x, minSum + x);

            answer = max(answer, max(abs(maxSum), abs(minSum)));
        }
        return answer;
    }
};
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int x = arr[i];

            int newNoDelete = max(x, noDelete + x);

            int newOneDelete;

            if (oneDelete == INT_MIN)
                newOneDelete = noDelete;
            else
                newOneDelete = max(noDelete, oneDelete + x);

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            answer = max(answer, max(noDelete, oneDelete));
        }

        return answer;
    }
};
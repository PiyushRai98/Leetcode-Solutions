class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        int n = matrix.size();

        for(int row=0; row<n; row++){
            pq.push({matrix[row][0], row, 0});
        }      

        for(int count=0; count<k; count++){
            auto [value, row, col] = pq.top();
            pq.pop();
            if(col+1<n){
                pq.push({matrix[row][col+1], row, col+1});

            }
            if(count == k-1){
                return value;
            }
        }

        return -1;
    }
};
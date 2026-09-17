class Solution {
public:

    vector<int> mergeArrays(vector<vector<int>>& mat) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        for(int i = 0; i < mat.size(); i++) {

            if(!mat[i].empty()) {
                pq.push({mat[i][0], i, 0});
            }
        }

        vector<int> ans;

        while(!pq.empty()) {

            auto [value, arrayIndex, elementIndex] = pq.top();

            pq.pop();

            ans.push_back(value);

            elementIndex++;

            if(elementIndex < mat[arrayIndex].size()) {

                pq.push({
                    mat[arrayIndex][elementIndex],
                    arrayIndex,
                    elementIndex
                });
            }
        }

        return ans;
    }
};
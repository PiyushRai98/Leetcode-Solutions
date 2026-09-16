class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;

        for(int row=0; row<mat.size(); row++){

            int sol = 0;
            for(int col=0; col<mat[row].size();col++){
                sol += mat[row][col];
            }

            pq.push({sol, row});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
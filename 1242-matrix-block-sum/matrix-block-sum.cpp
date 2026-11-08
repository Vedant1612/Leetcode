class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefixSum (rows+1, vector<int>(cols+1, 0));
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                prefixSum[i][j] = mat[i-1][j-1] + 
                                  prefixSum[i-1][j] +
                                  prefixSum[i][j-1] -
                                  prefixSum[i-1][j-1];
            }
        }

        vector<vector<int>> answer (rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int r1 = max(0, i-k);
                int c1 = max(0, j-k);
                int r2 = min(rows-1, i+k);
                int c2 = min(cols-1, j+k);

                r1++;
                c1++;
                r2++;
                c2++;

                answer[i][j] = prefixSum[r2][c2] -
                                   prefixSum[r1-1][c2] -
                                   prefixSum[r2][c1-1] +
                                   prefixSum[r1-1][c1-1];
            }
        }

        return answer;
    }
};
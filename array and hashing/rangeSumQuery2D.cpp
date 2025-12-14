class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        mat = vector<vector<int>>(m, vector<int>(n, 0));

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(c == 0){
                    mat[r][c] = matrix[r][c];
                    continue;
                }
                mat[r][c] = mat[r][c-1] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(mat.size() == 1 && mat[0].size() == 1) return mat[0][0];
        int sum = 0;
        for(int r = row1; r <= row2; r++){
            if(col1 > 0)
                sum += (mat[r][col2] - mat[r][col1 - 1]);
            else
                sum += mat[r][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
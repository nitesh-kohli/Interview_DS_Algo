class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //change 1D coordinates to 2D coordinates
        //flatten the array hypothetically
        int low = 0, high = rows*cols-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            //find row by mid
            int row = mid / cols;
            //find col by mid
            int col = mid % cols;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
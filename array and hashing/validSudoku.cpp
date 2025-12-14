class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       //check rows first
       for(int i = 0; i < 9; i++){
            set<char> s;
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch != '.' && s.count(ch)){
                    return false;
                }
                s.insert(ch);
            }
       }

       for (int j = 0; j < 9; j++) {
            set<char> s;
            for (int i = 0; i < 9; i++) {
                char ch = board[i][j]; // fixed column j, varying row i
                if (ch != '.' && s.count(ch)) {
                    return false;      // Duplicate in this column
                }
                s.insert(ch);
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                set<char> s;
                for(int m = i; m < i+3; m++){
                    for(int n = j; n < j+3; n++){
                        char ch = board[m][n]; // fixed column j, varying row i
                        if (ch != '.' && s.count(ch)) {
                            return false;      // Duplicate in this column
                        }
                        s.insert(ch);
                    }
                }
            }
        }

        return true;


    }
};
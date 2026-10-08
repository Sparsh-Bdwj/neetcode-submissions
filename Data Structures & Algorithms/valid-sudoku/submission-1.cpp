class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        for(int r =0; r<9; r++){
            for(int c =0; c<9; c++){
                char ch = board[r][c];
                if(ch == '.') continue;
                
                int num = ch - '1'; // 0-8
                int boxIdx = 3*(r/3)+(c/3);

                if(row[r][num] || col[c][num] || box[boxIdx][num]) return false;

                row[r][num] = 1;
                col[c][num] = 1;
                box[boxIdx][num] = 1;
            }
        }
        return true;
    }
};

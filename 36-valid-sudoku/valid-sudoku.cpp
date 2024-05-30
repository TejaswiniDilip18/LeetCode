class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        std::unordered_set<char> row[size];
        std::unordered_set<char> col[size];
        std::unordered_set<char> mat[size];
        bool is_valid;

        for(int i=0; i< size; i++){
            for(int j=0; j<size; j++){
                if(board[i][j]== '.') continue; //skip '.'

                if(row[i].count(board[i][j])) return false;
                row[i].insert(board[i][j]);

                if(col[j].count(board[i][j])) return false;
                col[j].insert(board[i][j]);

                int index = (i/3)*3 + (j/3);
                if(mat[index].count(board[i][j])) return false;
                mat[index].insert(board[i][j]);
            }
        }
        return true;
    }
};
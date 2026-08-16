class Solution {
public:
    int cnt = 0;
    int solve(int col, vector<string>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n){
        if(col == n){
            cnt++;
            return cnt;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, leftRow, lowerDiagonal, upperDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
        return cnt;
    }

    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++){
            board[i] = s;
        }

        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);

        return solve(0, board, leftRow, lowerDiagonal, upperDiagonal, n);
    }
};
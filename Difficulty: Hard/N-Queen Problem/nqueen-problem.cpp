// User function Template for C++

class Solution {
  public:
  bool isvalid(vector<int>& board, int row, int col) {
      for (int i = 0; i < row; i++) {
          // Check same column
          if (board[i] == col) {
              return false;
          }
          // Check left diagonal
          if (board[i] - i == col - row) {
              return false;
          }
          // Check right diagonal
          if (board[i] + i == col + row) {
              return false;
          }
      }
      return true;
  }

 void solve(int n, vector<int>& board, vector<vector<int>>& ans, int row) {
      // base case
      if (row == n) {
          ans.push_back(board);
          return;
      }

      for (int col = 0; col < n; col++) {
          if (isvalid(board, row, col)) {
              board[row] = col;
              solve(n, board, ans, row + 1);
              board[row] = -1;
          }
      }
  }

    vector<vector<int>> nQueen(int n) {
           vector<int> board(n, -1);
        vector<vector<int>> ans;
    
        solve(n, board, ans, 0);
    
        
        for (auto& sol : ans) {
            for (int& col : sol) {
                col += 1;
            }
        }
    
        return ans;
        }
};
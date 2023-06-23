#include<bits/stdc++.h>
using namespace std;

void solve(int i , int j , vector<string>&ans, vector<vector<int>>&vis, int di[], int dy[],string move, int n, vector<vector<int>>& a){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    string directions = "DLRU";

    for(int ind = 0;ind < 4;ind++){
        int nexti = i+di[ind];
        int nextj = j+dy[ind];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1){
            vis[i][j] = 1;
            solve(nexti, nextj , ans, vis, di , dy, move+directions[ind], n, a);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>>& m, int n ){
    vector<string>ans;
    vector<vector<int>>vis(n, vector<int>(n,0));//declare a visited matrix 
    int di[]={+1,0,-1,0};
    int dy[] = {0,+1,0,-1};
    
    if(m[0][0] == 1)solve(0,0,ans, vis, di, dy, "", n, m);

    return ans;
}

//! N Queen 
bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }


    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }

//! N -Queen efficient
void solve(int col , vector<int>&leftRow, vector<int>&upperDiagonal , vector<int>&lowerDiagonal, int n, vector<vector<string>>&ans, vector<string>&board){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row < n;row++){
            if(leftRow[row] == 0 && upperDiagonal[n-1+col-row] == 0 && lowerDiagonal[row+col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col+1, leftRow, upperDiagonal, lowerDiagonal, n, ans, board);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0 ;i<n;i++){
            board[i] = s;
        }
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1, 0);
        solve(0, leftRow, upperDiagonal , lowerDiagonal , n, ans, board);
        return ans;
    }
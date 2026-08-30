class Solution {
private:
    void dfs(int m, int n, vector<vector<int>>& vis, vector<vector<char>>& board,int row, int col){
        vis[row][col] = 1;

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(m, n, vis, board, nrow, ncol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || j == 0 || i == m-1 || j == n-1){
                        dfs(m, n, vis, board, i, j);
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
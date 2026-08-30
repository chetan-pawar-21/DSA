class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int row, int col){
        vis[row][col] = 1;

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<m
            && ncol>=0 && ncol<n
            && grid[nrow][ncol] == 1 
            && !vis[nrow][ncol]){

                dfs(grid, vis, m, n, nrow, ncol);

            }
        }


    }
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0] == 1){
                dfs(grid, vis, m, n, i, 0);
            }

            if(grid[i][n-1] == 1){
                dfs(grid, vis, m, n, i, n-1);
            }
        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 1){
                dfs(grid, vis, m, n , 0, j);
            }

            if(grid[m-1][j] == 1){
                dfs(grid, vis, m, n, m-1, j);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
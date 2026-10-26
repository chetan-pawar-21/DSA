class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n,long long& sum, int k){
        vis[row][col] = 1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nr = row+dr[i];
            int nc = col+dc[i];

            if(nr<m && nr>=0 && nc<n && nc>=0){
                if(grid[nr][nc] != 0 && !vis[nr][nc]){
                    dfs(nr, nc, grid, vis, m , n, sum, k);
                }
            }
        }
        sum+=grid[row][col];
        if(sum%k == 0){
            return 1;
        }
        return 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    long long sum = 0;
                    if(dfs(i, j, grid, vis, m, n, sum, k)) cnt++;
                }
            }
        }

        return cnt;
    }
};
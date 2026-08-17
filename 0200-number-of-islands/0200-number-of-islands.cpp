class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, int n, int m){
        if(r<0 || r>=n || c<0 || c>=m){
            return;
        }
        if(grid[r][c] != '1'){
            return;
        }

        grid[r][c] = '0';

        bfs(r+1,c,grid,n,m);
        bfs(r-1,c,grid,n,m);
        bfs(r,c+1,grid,n,m);
        bfs(r,c-1,grid,n,m);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
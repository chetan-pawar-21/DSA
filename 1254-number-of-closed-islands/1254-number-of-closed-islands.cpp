class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int row, int col, int n, int m)
    {
        if(row >= n || row < 0 || col >= m || col < 0) return false;
        if(grid[row][col] == 1) return true;
        grid[row][col] = 1;
        int up = dfs(grid,row-1,col,n,m);
        int down = dfs(grid,row+1,col,n,m);
        int left = dfs(grid,row,col-1,n,m);
        int right = dfs(grid,row,col+1,n,m);
        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    if(dfs(grid,i,j,n,m)) ans++;
                }
            }
        }
        return ans;
    }
};
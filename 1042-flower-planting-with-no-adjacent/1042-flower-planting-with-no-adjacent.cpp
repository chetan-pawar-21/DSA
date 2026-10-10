class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);

        for(auto it: paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }

        vector<int> color(n, 0);

        for(int i=0; i<n; i++){
            bool used[5] = {};

            for(int neighbor: adj[i]){
                used[color[neighbor]] = true;
            }

            for(int c = 1; c <= 4; c++){
                if(!used[c]){
                    color[i] = c;
                    break;
                }
            }
        }

        return color;
    }
};
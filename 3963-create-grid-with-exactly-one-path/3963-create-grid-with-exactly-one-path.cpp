class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        vector<string> ans;
        int i=0,j=0;
        bool flag = 0;
        while(i<m && j<n){
            mat[i][j] = 1;

            if(!flag){
                j=j+1;
                flag = 1;
            }else{
                i=i+1;
                flag=0;
            }
            
        }

        while(i<m){
            mat[i][j-1] = 1;
            i++;
        }

        while(j<n){
            mat[i-1][j] = 1;
            j++;
        }

        for(int row=0; row<m; row++){
            string s="";
            for(int col=0; col<n; col++){
                if(mat[row][col] == 1){
                    s+='.';
                }else{
                    s+='#';
                }
            }
            ans.push_back(s);
        }

        return ans;
        
    }
};
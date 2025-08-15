class Solution {
public:
    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int r, int c, int n, int m){
        // cout<<r<<" "<<c<<endl;
        for(int i=0; i<4; i++){
            int nr =r+dr[i], nc= c+dc[i];
            // cout<<nr<<" "<<nc<<" : ";
            if(nr>=1 && nr<n-1 && nc>=1 && nc<m-1 && vis[nr][nc]==0 && grid[nr][nc]==1 ){
                vis[nr][nc]=1 ;
                // board[nr][nc]='O';
                // cout<<"\n"<<"dfs of"<<nr<<nc<<"\n";
                dfs(grid, vis, nr, nc, n, m);
            }
        }
        // cout<<"\n";
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size(), cnt=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt+=grid[i][j];
            }
        }

        int x=0, y=m-1;
        for(int i=0; i<n; i++){
            if(vis[i][x]==0 && grid[i][x]==1){
                vis[i][x]=1;
                dfs(grid, vis, i, x, n, m);
            }
            if(vis[i][y]==0 && grid[i][y]==1){
                vis[i][y]=1;
                dfs(grid, vis, i, y, n, m);
            }
        }
        x=0; y=n-1;
        
        for(int j=0; j<m; j++){
            if(vis[x][j]==0 && grid[x][j]==1){
                vis[x][j]=1;
                // cout<<"\n"<<"dfs of"<<x<<j<<"\n";
                dfs(grid, vis, x, j, n, m);
            } 
            if(vis[y][j]==0 && grid[y][j]==1){
                vis[y][j]=1;
                // cout<<"\n"<<"dfs of"<<y<<j<<"\n";
                dfs(grid, vis, y, j, n, m);
            }                    
        }
        // board = vis
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                c+=vis[i][j];
            }
        }
        cout<<cnt<<" "<<c<<"\n";
        return  cnt - c;
    }
};
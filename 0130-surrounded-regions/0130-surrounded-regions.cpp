class Solution {
public:
    
    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, vector<vector<char>>&vis, int r, int c, int n, int m){
        // cout<<r<<" "<<c<<endl;
        for(int i=0; i<4; i++){
            int nr =r+dr[i], nc= c+dc[i];
            // cout<<nr<<" "<<nc<<" : ";
            if(nr>=1 && nr<n-1 && nc>=1 && nc<m-1 && board[nr][nc]=='O' && vis[nr][nc]=='X'){
                vis[nr][nc]='O';
                // board[nr][nc]='O';
                // cout<<"\n"<<"dfs of"<<nr<<nc<<"\n";
                dfs(board, vis, nr, nc, n, m);
            }
        }
        // cout<<"\n";
    }

    void solve(vector<vector<char>>& board) {
        //not to be on boundary and not connected to a boundary 0 
        int n= board.size(), m= board[0].size();
        vector<vector<char>>vis(n,vector<char>(m,'X'));
        // DFS on boundary
        int x=0, y=m-1;
        for(int i=0; i<n; i++){
            if(vis[i][x]=='X' && board[i][x]=='O'){
                vis[i][x]='O';
                dfs(board, vis, i, x, n, m);
            }
            if(vis[i][y]=='X' && board[i][y]=='O'){
                vis[i][y]='O';
                dfs(board, vis, i, y, n, m);
            }
        }
        x=0; y=n-1;
        
        for(int j=0; j<m; j++){
            if(vis[x][j]=='X' && board[x][j]=='O'){
                vis[x][j]='O';
                // cout<<"\n"<<"dfs of"<<x<<j<<"\n";
                dfs(board, vis, x, j, n, m);
            } 
            if(vis[y][j]=='X' &&board[y][j]=='O'){
                vis[y][j]='O';
                // cout<<"\n"<<"dfs of"<<y<<j<<"\n";
                dfs(board, vis, y, j, n, m);
            }                    
        }
        board = vis;
    }
};
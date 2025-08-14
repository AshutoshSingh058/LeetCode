class Solution {
public:
    int delrow[4]= {-1, 0, 1, 0};
    int delcol[4]= {0, 1, 0, -1};

    void dfs(vector<vector<int>>&dist, vector<vector<int>>&mat , int n, int m, int r, int c ){
        cout<<r<<" "<<c<<"\n";
        for(int i=0; i<4; i++){
            int nrow= r+ delrow[i], ncol = c + delcol[i];
            if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && mat[nrow][ncol]==1){
                if(dist[nrow][ncol]> dist[r][c]+1){
                    dist[nrow][ncol]= min(dist[nrow][ncol], dist[r][c]+1);
                    dfs(dist, mat, n ,m , nrow, ncol);
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>&dist, vector<vector<int>>&mat ,queue<pair<int,int>>q, int n, int m ){
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front(); q.pop();
                for(int i=0; i<4; i++){
                    int nrow= x+ delrow[i], ncol = y + delcol[i];
                    if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && mat[nrow][ncol]==1){
                        if(dist[nrow][ncol] > dist[x][y]+1){
                            dist[nrow][ncol] =  dist[x][y]+1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dist = mat;
        int n= mat.size(), m= mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]!=0)dist[i][j]= 1e9;
            }
        }
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    // dfs(dist, mat,  n , m , i, j); //TLE
                    q.push({i,j});
                }
            }
        }
        bfs(dist, mat, q,  n , m);
        return dist;
    }
};
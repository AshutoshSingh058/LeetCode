class Solution {
public:
    // BFS : queue based
    
    int delRow[4] = {-1, 0 , 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>> vis=grid;
        int time=-1, cnt=0;

        queue<pair<int,int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==2 ) q.push({i,j});          
                if(vis[i][j]==1)cnt++;
            }
        }
        if(cnt==0) return 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();     q.pop();
                for(int k = 0; k<4; k++) {
                    int i  = x + delRow[k], j = y + delCol[k];
                    if(i>=0 && i<n && j>=0 && j<m && vis[i][j]==1){
                        vis[i][j]=2;
                        cnt--;
                        q.push({i, j});
                    }
                } 
            }
            time++;
        }
        if(cnt !=0)return -1;
        return time;
    }
};
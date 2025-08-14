class Solution {
public:
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};

    void dfs(vector<vector<int>>& image,int stCol,int n, int m, int sr, int sc, int color){
        image[sr][sc]=color;
        for(int i=0; i<4; i++){
            int nrow= sr+delRow[i], ncol = sc+ delCol[i];
            if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && 
            image[nrow][ncol]!=color && image[nrow][ncol] == stCol ){
                
                image[nrow][ncol]=color;
                dfs(image, stCol, n,m, nrow, ncol, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stCol = image[sr][sc];
        int n = image.size(), m = image[0].size();
        image[sr][sc]=color;
        dfs(image, stCol, n, m, sr, sc, color);

        return image;
    }
};
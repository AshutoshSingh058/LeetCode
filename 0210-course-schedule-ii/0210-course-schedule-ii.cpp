class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<int>ans;
        vector<int> indegree(n,0), vis(n,0);

        for(int i=0; i<preq.size(); i++){
            indegree[preq[i][0]]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty()){
            int x= q.front(); ans.push_back(x); q.pop();
            for(int i=0; i<preq.size(); i++){
                if(preq[i][1]==x){
                    int y = preq[i][0];
                    indegree[y]--;
                    if(indegree[y] == 0 && vis[y]==0) {
                        vis[y]=1;
                        q.push(y);
                    }
                }
                
            }
        }

        if(ans.size()!=n)return {};
        return ans;
    }
};
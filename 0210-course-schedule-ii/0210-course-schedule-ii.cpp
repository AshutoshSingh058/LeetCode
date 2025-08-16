class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // build graph
        for (auto &p : preq) {
            adj[p[1]].push_back(p[0]);  // edge: p[1] -> p[0]
            indegree[p[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        // push nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        if ((int)ans.size() != n) return {};  // cycle → impossible
        return ans;
    }
};

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<int> result(k, 0);

        // Store queries with original indices for result mapping
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < k; i++) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        // Min-Heap (priority queue) to process grid cells in increasing order
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Start from (0,0)
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        // Directions for moving in 4 directions
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int count = 0, idx = 0;

        // Process queries in sorted order
        while (idx < k) {
            int curr_query = sorted_queries[idx].first;
            int query_index = sorted_queries[idx].second;

            // Expand BFS while the grid value is smaller than current query
            while (!minHeap.empty() && minHeap.top().first < curr_query) {
                auto [val, cell] = minHeap.top();
                minHeap.pop();
                int i = cell.first, j = cell.second;

                count++; // Increment count of reachable cells

                // Explore neighbors
                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        minHeap.push({grid[ni][nj], {ni, nj}});
                    }
                }
            }

            result[query_index] = count;
            idx++;
        }

        return result;
    }
};

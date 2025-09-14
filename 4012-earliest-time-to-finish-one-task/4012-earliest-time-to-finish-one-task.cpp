class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int t = 1e7;
        for(int i=0; i<tasks.size(); i++){
            t = min(t, tasks[i][0]+tasks[i][1]);
        }
        return t;
    }
};
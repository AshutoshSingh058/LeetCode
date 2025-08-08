class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> v1;
        if (v.empty()) return v1;

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        v1.push_back(v[0]);
        for (int i = 1; i < v.size(); i++) {

            vector<int>& last = v1.back();
            
            if (last[1] >= v[i][0]) {
                last[1] = max(last[1], v[i][1]);
            } else {
                v1.push_back(v[i]);
            }
        }
        return v1;
    }


    vector<vector<int>> insert(vector<vector<int>>&v, vector<int>&vi) {
        v.push_back(vi);
        sort(v.begin(), v.end());
        return merge(v);
    }
};
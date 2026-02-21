class Solution {
public:
    int n=0;

    void func(vector<int>& candidates,int &target, int start, int sum, vector<int> &v, vector<vector<int>>&ans){
        if( sum > target) return;
        if(sum == target){
            // sort(v.begin(), v.end());
            ans.push_back(v);
            return;
        }

        for(int i=start; i<n; i++){
            if(i> start && candidates[i] == candidates[i-1])continue;
            v.push_back(candidates[i]);
            func(candidates, target, i+1, sum + candidates[i], v, ans);
            v.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        n = candidates.size(); 
        func(candidates, target, 0, 0, v, ans);

        return ans;
    }
};
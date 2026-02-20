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
            v.push_back(candidates[i]);
            func(candidates, target, i, sum + candidates[i], v, ans);
            v.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> v;
        n = candidates.size(); 
        func(candidates, target, 0, 0, v, ans);

        return ans;
    }
};
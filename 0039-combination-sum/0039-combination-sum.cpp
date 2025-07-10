class Solution {
public:
    void func(vector<int>& candidates, int target, int sum, vector<int>v, 
    vector<vector<int>>&vec, int start){
        if(sum == target){
            vec.push_back(v);
        }
        for(int i=start; i<candidates.size(); i++){
            if(sum + candidates[i] <= target){
                v.push_back(candidates[i]);
                func(candidates, target, sum + candidates[i], v, vec, i);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>vec;
        int sum =0;
        vector<int>v;
        func(candidates, target, sum, v , vec , 0 );
        return vec;
    }
};
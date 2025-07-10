class Solution {
public:
    void func(vector<int>& candidates, int target, int sum, vector<int>v, 
    set<vector<int>>&vec, int start){
        if(sum == target){
            vec.insert(v);
        }
        for(int i=start; i<candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Break early since array is sorted
            if (candidates[i] > target)
                break;
                
            if(sum + candidates[i] <= target){
                v.push_back(candidates[i]);
                func(candidates, target, sum + candidates[i], v, vec, i+1);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>vec;
        vector<vector<int>>v2;
        int sum =0;
        vector<int>v;
        sort(candidates.begin(), candidates.end());
        func(candidates, target, sum, v , vec , 0 );
        for(auto &i: vec){
            v2.push_back(i);
        }
        return v2;
    }
};
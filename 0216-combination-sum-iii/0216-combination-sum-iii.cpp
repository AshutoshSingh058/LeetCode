class Solution {
public:
    void rec(set<vector<int>>&vec, int k, int n, vector<int>v, vector<int>v2, int pos, int sum){
        // if(9-pos> k-sum)return;
        if(sum == n && v2.size()==k) vec.insert(v2);
        if(pos>=9)return;
        
        v2.push_back(v[pos]);
        rec(vec, k, n, v, v2, pos+1, sum+v[pos]);
        v2.pop_back();
        rec(vec, k, n, v, v2, pos+1, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>>vec;
        vector<int> v ={1,2,3,4,5,6,7,8,9};  
        vector<int>v2;
        rec(vec, k, n, v, v2, 0 , 0 );

        vector<vector<int>>answer(vec.begin(), vec.end());
        return answer;
    }
};
class Solution {
public:

    void rec(set<vector<int>> &st, vector<int>& nums, vector<int>&temp, int index ){
    if(index == nums.size()){
        st.insert(temp);
        return;
    }
    temp.push_back(nums[index]);
    
    rec(st, nums, temp, index+1);
    temp.pop_back();
    rec(st, nums, temp, index+1);
}


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        vector<int>temp;
        rec(st, nums, temp, 0);
        vector<vector<int>>v(st.begin(), st.end());
        return v;       
    }
};
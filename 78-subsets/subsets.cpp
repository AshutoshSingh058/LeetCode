class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
    
        int m=1<<n;
        for(int i=0; i<m; i++){
            int c=i, x=0;
            vector<int> arr;
            while(c>= (1<<x)){
                if( c & (1<<x))arr.push_back(nums[x]);
                x++;
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        //so need to return the keys which repeat.
        set<int>s;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==key){
                for(int j = i-k; j<=i+k; j++)
                if(j>=0 && j<n)s.insert(j);
            }
        }
        vector<int>vec;
        for(auto i: s)vec.push_back(i);

        return vec;
    }
};
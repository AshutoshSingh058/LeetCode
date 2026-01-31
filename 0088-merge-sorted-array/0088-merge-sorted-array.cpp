class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n, j=0;
        // vector<int> vec(k);
        for(int i=0; i<n; i++){
            nums1[i+m] = nums2[i]; 
        }

        // for(int i=0; i<n; i++){
        //     vec[j] = nums2[i]; j++;
        // }
        sort(nums1.begin(), nums1.end());
        // nums1 = vec;
    }
};
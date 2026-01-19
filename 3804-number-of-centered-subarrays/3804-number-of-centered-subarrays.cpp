class Solution {
public:
    
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), tot=0, s=0;
        map<int, int> mp;

        for(int i=0; i<n; i++){
            s = 0;
            for(int j=i; j<n; j++){
                s+= nums[j];

                for(int k=i; k<=j; k++){
                    if(s == nums[k]) {
                        tot++;
                        break;
                    }
                }
            }
        }
        return tot;
    }
};
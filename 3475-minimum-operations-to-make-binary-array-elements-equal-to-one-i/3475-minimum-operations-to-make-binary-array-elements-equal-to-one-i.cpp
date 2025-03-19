class Solution {
public:
    int minOperations(vector<int>& v) {
        int n=v.size(), c=0;
        for(int i=0; i<n-2; i++){
            if(v[i]==0){
                v[i]^=1;
                v[i+1]^=1;
                v[i+2]^=1;
                c++;
            }

        }
        if(v[n-1]==1 && v[n-2]==1 && v[n-3]==1)return c;
        else return -1;
    }
};
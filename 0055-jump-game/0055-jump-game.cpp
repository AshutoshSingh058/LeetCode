class Solution {
public:
    bool canJump(vector<int>& v) {
        int n= v.size(), x=0;
        bool a = true;
        for(int i=0; i<n; i++){
            if(x<i)return false;
            x=max(x, i+v[i]);
        }
        // if(x+1 >= n)
        return true;
        // return false;
    }
};
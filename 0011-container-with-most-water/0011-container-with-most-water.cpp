class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size(), l=0, r =n-1, w=0, mw=0;
        while(l<r){
            w = min(height[l], height[r])*(r-l);
            mw = max(w, mw);
            if(height[l]> height[r])r--;
            else l++;
        }
        return mw;
    }
};
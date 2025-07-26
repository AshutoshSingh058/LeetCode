class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0,n=cardPoints.size(), maxsum=0;

        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }
        maxsum=max(maxsum, lsum+rsum);    
        for(int i=1; i<=k; i++){
            rsum+=cardPoints[n-i];
            lsum-=cardPoints[k-i];
            maxsum=max(maxsum, lsum+rsum);
        }
        return maxsum;
    }
};
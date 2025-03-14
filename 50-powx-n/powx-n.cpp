class Solution {
    public:
    double myPow(double x, int n) {
        double ans=1.0;
        long nn=abs((long)n);
        while(nn>0){
            if(nn%2==1){
                ans=ans*x;
                nn--;
            }else{
                x=(x*x);
                nn/=2;
            }
        }
        return (n>=0)?ans:(1.0/ans);
    }
};
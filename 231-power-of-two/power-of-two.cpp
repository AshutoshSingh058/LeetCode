class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;

        bool n2= (n&(n-1)) ==0;
        cout<< (n&(n-1));
        return n2;
    }
};
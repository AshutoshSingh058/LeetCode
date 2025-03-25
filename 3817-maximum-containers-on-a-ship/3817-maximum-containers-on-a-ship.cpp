class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int wtadd = n*n*w, x=n*n;
        
        if(wtadd<=maxWeight)return x;
        while(true){
            x--;
            wtadd-=w;
            if(wtadd<=maxWeight)return x;
        }
        
    }
};
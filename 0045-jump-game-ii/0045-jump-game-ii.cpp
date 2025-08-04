class Solution {
public:
    int jump(vector<int>& v) {
        int n=v.size(), x=0,y=0, xc=0, i=0;
        
        if(xc>=n-1)return 0;
        y++; xc=max(xc, 0+v[0]);
        while(true){
            if(xc>=n-1)break;   
            for( int j=i+v[i]; j>=i; j--){
                if(j+v[j]>xc){
                    xc=j+v[j];
                    x=j;
                }
            }
            y++;
            cout<<xc<<endl;
            
            if(xc>=n-1)break;   
            i=x;
        }
        return y;
    }
};
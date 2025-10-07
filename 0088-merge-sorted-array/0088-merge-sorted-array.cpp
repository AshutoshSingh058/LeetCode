class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        // int x=0, y=0;
        // vector<int>vc;
        for(int i=m; i<m+n; i++){
            v1[i]=v2[i-m];
        }
        sort(v1.begin(), v1.end());
        // while(x<m&& y<n){
        //     if(v1[x]<v2[y] ){
                
        //         if((x+y)<m)vc.push_back(v1[x]);
        //         x++;
        //     }
        //     else{
        //         vc.push_back(v2[y]);
        //         y++;
        //     }
        // }
        // while(x<m){
        //     vc.push_back(v1[x]);
        //     x++;
        // }
        // while( y<n){
        //     vc.push_back(v2[y]);
        //     y++;
        // }

        // // for(int i=0 ; i<vc.size(); i++){
        // //     cout<<vc[i]<<" ";
        // // }
        // v1=vc;
    }
};
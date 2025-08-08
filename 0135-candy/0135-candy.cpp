class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size(), c=1;
        vector<int> v1(n), v2(n);
        v1[0]=1;
        v2[n-1] =1;
        for(int i=1;i<n; i++){
            if(ratings[i]>ratings[i-1]){
                c++; v1[i]=c;
            }
            else{
                c=1; v1[i]=c;
            }
        }
        c=1;
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                c++; v2[i]=c;
            }
            else{
                c=1; v2[i]=c;
            }
        }
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+= max(v1[i], v2[i]);
            cout<<v1[i]<< " "<< v2[i]<<endl;
        }

        return sum;
    }
};
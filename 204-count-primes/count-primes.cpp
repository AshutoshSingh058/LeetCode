class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n+1,1);
        arr[0]=arr[1]=0;
        int count =0;
        for(int i=2; i<n;i++){
            // arr[i]=-1;
            if( !arr[i] )continue;
            count++;
            for(int j=i*2; j<n; j+=i){
                arr[j]=0;
            }
            
        }
        // for(int i=0; i<=n;i++)cout<<arr[i]<<" ";
        return count;
    }
};
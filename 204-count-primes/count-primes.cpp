class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n+1,1);
        arr[0]=arr[1]=0;
        int count =0;
        for(int i=2; i*i<n;i++){
            // arr[i]=-1;
            if(arr[i] == 0)continue;
            // count++;
            for(int j=i*i; j<n; j+=i){
                arr[j]=0;
            }
            
        }
        for(int i=0; i<n;i++)count+=arr[i];
        return count;
    }
};
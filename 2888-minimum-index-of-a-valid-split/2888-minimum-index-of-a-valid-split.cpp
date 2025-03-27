class Solution {
public:
    int minimumIndex(vector<int>& v) {
        int n = v.size(), m=0, k=0;
        k = v[0];
        for(int i=0; i<n; i++){
            if(v[i] == k)m++;
            else{
                m--;
                if(m==0) k = v[i+1];
            }
        }
        //thus k is the max freq element of the list.
        cout<<k<<endl;
        int cnt =0, ans=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(v[i]==k)cnt2++;
        }
        if(2*cnt2 > n+1){
            for(int i=0; i<n; i++){
                if(v[i]==k)cnt++;
                if(cnt*2 > i+1){
                    cout<<i;
                    return i;
                }
            }
        }
        return -1;
    }
};
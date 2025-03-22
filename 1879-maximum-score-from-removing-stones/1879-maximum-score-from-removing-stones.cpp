class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int>v={a,b,c};
        int cnt =0;
        sort(v.begin(), v.end());
        while(v[0]+v[1]>v[2]){
            cnt++;
            v[0]--; v[1]--;
            if(v[0]<=0)break;
        }
        cnt+=v[0]+v[1];
        return cnt;
    }
};
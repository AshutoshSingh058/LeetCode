class Solution {
public:
    bool func( int i, int j, string a, string b, vector<int>& v){
        int n = a.size(), diff=0, newdiff =0;
        if(b[0] < a[0] )diff = int(b[0]+26 - a[0]);
        else diff = int(b[0] - a[0]);
        // cout<<diff<<" ";
        for(int i=0; i<n; i++){
            if(b[i] < a[i]) newdiff = int(b[i]+26 - a[i]);
            else newdiff = int(b[i] - a[i]);
            // cout<<newdiff<<" ";
            if(newdiff != diff) return false;
        }
        v[j] = 1;
        return true;
    }

    long long countPairs(vector<string>& words) {
        long long n = words.size(), c=0, tot=0;
        // vector<int, vector<int>>v (n, vector<int>);
        vector<int> v(n,0);
        for(int i=0; i<n; i++) {
            if(v[i] == 1) continue;
            c=1;
            v[i] = 1;
            for(int j=i+1; j<n; j++){
                c+= func( i, j, words[i], words[j], v);

            }
            tot+=c*(c-1)/2;
        }
        return tot;
    }
};
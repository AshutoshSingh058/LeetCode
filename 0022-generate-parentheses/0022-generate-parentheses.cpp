class Solution {
public:
    void rec(int c1, int c2, int n, string s, vector<string> &v){
        if(c1==n && c2==n){
            v.push_back(s);
        }
        if(c1<n)rec(c1+1, c2, n, s+'(', v);
        if(c2<c1 && c2<n)rec(c1, c2+1, n, s+')', v);
    }
    

    vector<string> generateParenthesis(int n) {
        vector<string>v;

        rec(0, 0, n, "", v);

        return v;
    }
};
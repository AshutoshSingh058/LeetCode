class Solution {
public:
    string reversePrefix(string s, int k) {
        string ss = s.substr(0, k);
        cout<<ss <<" " <<endl;
        reverse(ss.begin(), ss.end());
        string ss2 = s.substr(k, s.size()-k);
        cout<<ss <<" " << ss2<<endl;
        string st = ss + ss2;

        return st;
    }
};
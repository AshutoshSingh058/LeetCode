class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        int n =  s.length();
        stk.push(s[0]);
        for(int i=1; i<n; i++){
            if(!stk.empty() && (int(s[i]-'a')==int(stk.top()-'A') || int(s[i]-'A')==int(stk.top()-'a')) ){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        string st = "";
        while(!stk.empty()){
            st+=stk.top(); stk.pop();
        }
        reverse(st.begin(), st.end());
        return st;
    }
};
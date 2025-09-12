class Solution {
public:
    int minAddToMakeValid(string s) {
        int a = 0;
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')st.push('(');
            else {
                if(!st.empty() && st.top() =='(')st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
};
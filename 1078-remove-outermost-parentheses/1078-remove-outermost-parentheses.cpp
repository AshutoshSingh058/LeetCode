class Solution {
public:
    string removeOuterParentheses(string s) {
        string st="";
        bool flag = false;
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(cnt==0 && flag ==false && s[i]=='('){
                flag =true;
            }
            else if(cnt==0 && flag==true && s[i]==')'){
                flag = false;
            }
            else{
                st+=s[i];
                if(s[i]=='(')cnt++;
                else cnt--;
            }
        }

        return st;
    }
};
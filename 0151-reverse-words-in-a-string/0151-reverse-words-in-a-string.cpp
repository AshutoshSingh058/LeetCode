class Solution {
public:
    string reverseWords(string s) {
        string  st ="";
        int n=s.size();
        vector<string> v;
        for(int i=0; i<n; i++){
            if(s[i]==' '){
                if(st != "")v.push_back(st); st="";
            }
            else st+=s[i];
        }
        if(st != "")v.push_back(st);
        st="";
        for(int i=v.size()-1; i>=0; i--){
            st += v[i]; 
            if(i!=0)st+=" ";
        }
        return st;
    }
};
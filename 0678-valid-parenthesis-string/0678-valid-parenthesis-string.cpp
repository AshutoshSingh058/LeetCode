class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), a=0, c=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                a++; c++;
            }
            else if(s[i]== ')'){
                a--; c--;
            } 
            else{
                a--; c++;
            }
            if(c<0) return false;
            if(a<0) a=0;
        }
        cout<<a <<" "<<c<<" ";
        
        return a==0;
    }
};
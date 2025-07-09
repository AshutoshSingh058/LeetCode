class Solution {
public:
    int myAtoi(string s) {

        int x =0;
        while(x<s.size()){
            if(s[x]==' ')x++;
            else break;
        }
        cout<<x<<endl;
        int sign =1;
        if(s[x]=='-'){
            sign =-1; x++; 
        }
        else if(s[x]== '+'){sign =1; x++;}
        cout << sign;
        long long a=0;
        // string st = "";
        for(int i=x; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                if(sign == 1 && a*10 + int(s[i]-'0') >=INT_MAX) return INT_MAX;
                if(sign == -1 && a*10 + int(s[i]-'0') >INT_MAX) return INT_MIN;
                a*=10;
                // st+=s[i];
                a+=int(s[i]-'0');
            }

            else break;
        }
        
        return sign*a;
    }
};
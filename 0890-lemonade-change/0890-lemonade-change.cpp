class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        int n= v.size(), f=0,t=0, tw=0, total=0;

        for(int i=0; i<n; i++){
            if(v[i]==5){ 
                f++; total+=5;
            }
            else if(v[i] == 10 && f>0){
                f--; t++; total+=5;
            }
            else if(v[i] == 20 && total>=15 ){
                if(t>0 && f>0){t--; f--;}
                else if(f>=3){ f-=3;}
                else return false;
                total+=5;
            }
            else return false;
        }
        return true;
    }
};
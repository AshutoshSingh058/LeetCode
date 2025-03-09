class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int a=0,r=0, b=0, c=0, n= colors.size();
        vector<int>vec;
        vector<int>diffvec;

        for(int i=0; i<n; i++){
            if(colors[i]==colors[(i+1)%n]){
               vec.push_back(i);
            }
        }
        if(vec.size()==0)return n;
        if(vec.size()<2)diffvec.push_back(n);
        else{
            for(int i=1; i<vec.size(); i++){
                diffvec.push_back(vec[i]-vec[i-1]);
            }
            diffvec.push_back(n- vec[vec.size()-1] + vec[0]);
        }
        for(int i=0; i<diffvec.size(); i++){
            cout<<diffvec[i]<<" ";
            c+=max(0, diffvec[i]-k+1);
        }
        
        return c;
    }
};
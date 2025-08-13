class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxL= INT_MAX;
        string s="";
        for(int i=0; i<strs.size(); i++){
            maxL = min(maxL, (int)strs[i].size());
        }

        for(int i=0; i<maxL; i++){
            bool flag= true;
            char ch= strs[0][i];
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i]!=ch)flag = false;
            }
            if(flag==false)break;
            s+=ch;
        }
        return s;
    }
};
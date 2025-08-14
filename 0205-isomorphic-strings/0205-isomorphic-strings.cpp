class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n= s.size();
        bool flag = true;
        map<char,char> mp, mp2;
        
        for(int i=0; i<n; i++){
            mp[s[i]]=t[i];
        }
        for(int i=0; i<n; i++){
            if(mp[s[i]]!=t[i])return false;
        }

        for(int i=0; i<n; i++){
            mp2[t[i]]=s[i];
        }
        for(int i=0; i<n; i++){
            if(mp2[t[i]]!=s[i])return false;
        }

        return true;
    }
};
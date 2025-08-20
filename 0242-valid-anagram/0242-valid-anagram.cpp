class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0), v(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0; i<s.size(); i++){
            vec[s[i]-'a']++;
            v[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(v[i]!=vec[i]) return false;
        }
        return true;
    }
};
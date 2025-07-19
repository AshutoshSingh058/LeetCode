class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0, l=0, r=0;
        map<int,int>mp;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]]==1){
                while(mp[s[i]]==1){
                    mp[s[l]]--;
                    l++;
                }    
            }
            mp[s[i]]++;
            len= max(len, i-l+1);
        }
        return len;
    }
};
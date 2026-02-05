class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n=s.size(), m= words.size(), wordLen = words[0].size(), totalLen = m * wordLen;
        vector<int> v;
        unordered_map<string, int> mp2;
        if(n< totalLen) return v;
        for(int i=0; i<m; i++){
            mp2[words[i]]++;
        }

        for(int i=0; i<wordLen; i++){
            unordered_map<string, int>  mp;
            int l= i, r =i, c=0;
            
            while(r + wordLen <=n){
                string w = s.substr(r, wordLen);
                r+=wordLen;

                if(mp2.count(w)== 0){
                    mp.clear();
                    c =0;
                    l=r;
                }
                else {
                    mp[w]++;
                    c++;
                    while(mp[w]>mp2[w]){
                        string lw = s.substr(l,wordLen);
                        mp[lw]--;
                        c--;
                        l+=wordLen;
                    }
                    if(c == m){
                        v.push_back(l);

                        string lw = s.substr(l, wordLen);
                        mp[lw]--;
                        c--;
                        l+=wordLen;
                    }
                }

            }

        }
        return v;

    }
};
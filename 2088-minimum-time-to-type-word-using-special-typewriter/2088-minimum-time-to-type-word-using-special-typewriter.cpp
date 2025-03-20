class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size(), c=n, k=0;
        c+=min(min(abs(int('a'-word[0])), abs(26-int('a'-word[0]))),min(abs(int(word[0]-'a')), abs(26-int(word[0]-'a'))));
        // cout<<abs(int('a'-word[0]))<<" "<<abs(26-int('a'-word[0]))<<" "<<abs(int(word[0]-'a'))<<" "<<abs(26-int(word[0]-'a'));
        cout<<int(word[0]-'a')<<" "<<c<<endl;
        for(int i=1; i<n; i++){
            c+=min(min(abs(int(word[i-1]-word[i])), abs(26-int(word[i-1]-word[i]))),min(abs(int(word[i]-word[i-1])), abs(26-int(word[i]-word[i-1]))));
            cout<<c<<endl;
        }
        return c;
    }
};
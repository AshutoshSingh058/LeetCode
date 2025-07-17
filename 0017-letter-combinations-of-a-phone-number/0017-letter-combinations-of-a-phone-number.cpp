class Solution {
public:
    void rec(vector<string>&ans,unordered_map<char, string>& mapping, string&digits, string s, int index ){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        string st = mapping[digits[index]];
        for(int i=0; i<st.size(); i++){
            rec(ans, mapping, digits, s+st[i], index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<char, string> mapping = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},{'6', "mno"},      {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

        if(digits.size()==0)return ans;
    
        rec(ans, mapping, digits, "", 0 );
        return ans;
    }
};
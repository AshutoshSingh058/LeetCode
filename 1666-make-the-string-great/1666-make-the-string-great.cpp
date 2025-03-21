class Solution {
public:
    bool check(char a, char b) {
        if ((a | 0x20) != (b | 0x20))
            return false;
        return (((a ^ b) & 0x20));
    }

    string makeGood(string &s) {
        stack<char> st;
        for (auto &&ch: s) {
            if (!st.empty()) {
                if (check(st.top(), ch))
                    st.pop();
                else
                    st.push(ch);
            } else 
                st.push(ch);
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string> st(wl.begin(), wl.end());
        if (!st.count(ew)) return 0;

        queue<string> q;
        q.push(bw);
        int cnt = 1;  // bw counts as step 1

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string w = q.front();
                q.pop();

                if (w == ew) return cnt;

                for (int i = 0; i < w.size(); i++) {
                    char org = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[i] = c;
                        if (st.count(w)) {
                            q.push(w);
                            st.erase(w);
                        }
                    }
                    w[i] = org;
                }
            }
            cnt++;
        }
        return 0;
    }
};

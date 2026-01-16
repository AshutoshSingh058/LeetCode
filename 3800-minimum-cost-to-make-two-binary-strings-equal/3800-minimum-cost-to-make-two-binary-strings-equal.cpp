#define ll long long

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long a=0, b=0, n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]== t[i]) continue;
            if(s[i] == '1') a++;
            if(s[i] == '0') b++;

        }
        ll k = a + b;

        // Case 1: Flip everything
        ll cost1 = 1LL * flipCost * k;

        // Case 2: Use swaps where possible
        ll pairs = min(a, b);
        ll cost = 1LL * swapCost * pairs;

        a -= pairs;
        b -= pairs;
        k -= 2 * pairs;

        // Case 2(i): flip remaining
        ll cost2 = cost + 1LL * flipCost * k;

        // Case 2(ii): cross + swap for pairs, flip if odd
        ll cost3 = cost + (k / 2) * 1LL * (crossCost + swapCost) +
                   (k % 2) * 1LL * flipCost;

        return min({cost1, cost2, cost3});

    }
};
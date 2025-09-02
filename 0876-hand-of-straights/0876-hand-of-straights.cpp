class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int,int> count;
        priority_queue<int, vector<int>, greater<int>> pq;

        // count frequencies
        for (int card : hand) {
            if (count[card] == 0) pq.push(card);
            count[card]++;
        }

        // process smallest available card
        while (!pq.empty()) {
            int start = pq.top();
            pq.pop();

            if (count[start] == 0) continue; // already used

            int need = count[start];
            // build group [start, start+1, ..., start+groupSize-1]
            for (int i = 0; i < groupSize; i++) {
                if (count[start + i] < need) return false;
                count[start + i] -= need;
            }
        }
        return true;
    }
};

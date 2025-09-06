class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> follows; // who follows whom
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> {time, tweetId}

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // max heap by time
        vector<int> result;

        // Add self
        follows[userId].insert(userId);

        // Collect latest tweets from user and followees
        for (int followee : follows[userId]) {
            for (auto &t : tweets[followee]) {
                pq.push(t); // (time, tweetId)
            }
        }

        // Extract top 10
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId) // cannot unfollow self
            follows[followerId].erase(followeeId);
    }
};

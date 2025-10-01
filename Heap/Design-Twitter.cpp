// Keep trach of k recent eleemtns
// Min heap of size k
// Cnt to keep track of time

class Twitter {
public:
    unordered_map<int, deque<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;
    int cnt = 0;
    //A global cnt variable
    //To allow us to track recency of tweets
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end())
            tweets[userId] = deque<pair<int, int>>();
        if(tweets[userId].size() == 10)
        {
            //remove the oldest tweet
            tweets[userId].pop_front();
        }
        tweets[userId].push_back({cnt++, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxHeap;

        followers[userId].insert(userId);

        for(int follower: followers[userId])
        {
            for(auto& p: tweets[follower])
            {
                if(maxHeap.size() < 10)
                    maxHeap.push(p);
                else if(maxHeap.top().first < p.first)
                {
                    maxHeap.pop();
                    maxHeap.push(p);
                }
            }
        }

        while(!maxHeap.empty())
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

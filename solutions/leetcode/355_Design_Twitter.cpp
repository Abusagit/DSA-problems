#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;


// struct TweetMetaInfo {
//     TweetMetaInfo(int x, int y, int z, int m): tweet_id(x), user_id(y), followee_id(z), index_in_array(m) {}
//     int tweet_id;
//     int user_id;
//     int followee_id;
//     int index_in_array;
// };


class TupleComparator {
public:
    bool operator() (tuple<int, int, int, int>& A, tuple<int, int, int, int>& B) {
        return get<0>(A) < get<0>(B); // decreasing order
    }
};

class Twitter {
public:
    Twitter() {
        this->tweets_counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets_map[userId].push_back(make_tuple(tweetId, tweets_counter));
        tweets_counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);

        vector<tuple<int, int, int, int>> tweets_pq;

        for (auto followeeId: followMap[userId]){

            if (user_tweets_map.find(followeeId) == user_tweets_map.end()){
                continue;
            }
            int n = user_tweets_map[followeeId].size() - 1;

            int tweetId, tweet_ordering;

            tie(tweetId, tweet_ordering) = user_tweets_map[followeeId][n];

            tweets_pq.push_back(make_tuple(tweet_ordering, tweetId, followeeId, n - 1));

        }

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, TupleComparator> pq(tweets_pq.begin(), tweets_pq.end());

        vector<int> result;

        while (!pq.empty() && result.size() < 10){
            int tweetId, tweet_ordering, followeeId, next_index;
            tie(tweet_ordering, tweetId, followeeId, next_index) = pq.top();
            pq.pop();
            result.push_back(tweetId);

            if (next_index >= 0){
                tie(tweetId, tweet_ordering) = user_tweets_map[followeeId][next_index];
                pq.push(make_tuple(tweet_ordering, tweetId, followeeId, next_index - 1));
            }
        }


        return result;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }

private:
    int tweets_counter;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<tuple<int, int>>> user_tweets_map;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
#include <iostream>
#include <vector>
#include <map>
#include <utility> 
#include <algorithm>
using namespace std;

class Twitter {
private:
  //follower->followees
  map<int, vector<int> > followMap;
  //user->my post
  map<int, map<int, int> > postMap;
  //time stardand
  int time;
public:
  /** Initialize your data structure here. */
  Twitter() {
    time = 0;
  }
  
  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    if(postMap.find(userId) == postMap.end()) {
      pair<int, int> p = make_pair(time, tweetId);
      map<int, int> tempMap;
      tempMap.insert(p);
      pair<int, map<int, int>> pp = make_pair(userId, tempMap);
      postMap.insert(pp);
      time++;
    } else {
      pair<int, int> p = make_pair(time, tweetId);
      postMap[userId].insert(p);
      time++;
    }
  }
  
  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> result;
    map<int, int> tweet;
    //my own
    if(postMap.find(userId) != postMap.end()) {
      tweet = postMap[userId];
    }
    //follow
    if(followMap.find(userId) != followMap.end()) {
      for(auto a : followMap[userId]) {
        if(postMap.find(a) != postMap.end()) {
          map<int, int> t = postMap[a];
          for(auto at : t) {
            tweet.insert(at);
          }
        }
      }
    }

    // reverse(tweet.begin(), tweet.end());
    if(tweet.size() >= 10) {
      int i = 0;
      for(auto it = tweet.rbegin(); it != tweet.rend(); it++) {
        result.push_back(it->second);
        i++;
        if(i == 10) {
          break;
        }
      }
    } else {
      for(auto it = tweet.rbegin(); it != tweet.rend(); it++) {
        result.push_back(it->second);
      }
    }

    return result;
  }
  
  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    if(followMap.find(followerId) == followMap.end()) {
      vector<int> t{followeeId};
      followMap.insert(pair<int, vector<int>>(followerId, t));
    } else {
      followMap[followerId].push_back(followeeId);
    }
  }
  
  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if(followMap.find(followerId) != followMap.end() && find(followMap[followerId].begin(), followMap[followerId].end(), followeeId) != followMap[followerId].end()) {
      followMap[followerId].erase(find(followMap[followerId].begin(), followMap[followerId].end(), followeeId));
    }
  }
};

int main() {
  Twitter twitter;

  // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
  twitter.postTweet(1, 5);

  // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
  vector<int> r1 = twitter.getNewsFeed(1);
  for(auto a : r1) {
    cout << a << ", ";
  }
  cout << endl;

  // 用户1关注了用户2.
  twitter.follow(1, 2);

  // 用户2发送了一个新推文 (推文id = 6).
  twitter.postTweet(2, 6);

  // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
  // 推文id6应当在推文id5之前，因为它是在5之后发送的.
  vector<int> r2 = twitter.getNewsFeed(1);
  for(auto a : r2) {
    cout << a << ", ";
  }
  cout << endl;

  // 用户1取消关注了用户2.
  twitter.unfollow(1, 2);

  // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
  // 因为用户1已经不再关注用户2.
  vector<int> r3 = twitter.getNewsFeed(1);
  for(auto a : r3) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}
/**
 * 设计推特
 * 可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 */

/**
 * 设计思路: 
 * 
 * TODO 带理解
 */
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

// 推文结构体
struct Twit {  
    int twit_id;
    int timestamp; // 时间戳
    Twit* next;
    Twit(int twit_id, int timestamp): twit_id(twit_id), timestamp(timestamp), next(nullptr) {}
};

// 时间戳比较
struct Compare {
    bool operator () (const Twit* twit1, const Twit* twit2) {
        return twit1->timestamp < twit2->timestamp;
    }
};

class Twitter {

private:
    map<int, set<int>> id_follow_list;  // 用户到关注列表的映射
    map<int, Twit*> id_twit_list;  // 用户到推文列表的映射

    int timestamp;

public:
    /** Initialize your data structure here. */
    Twitter(): timestamp(0) {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Twit* twit = new Twit(tweetId, ++timestamp);

        Twit* last_head = id_twit_list[userId];
        id_twit_list[userId] = twit;
        twit->next = last_head;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Twit*, vector<Twit*>, Compare> recent_twits;
        // userId自己发的twit
        if (id_twit_list.find(userId) != id_twit_list.end()) {
            Twit* current_twit = id_twit_list[userId];
            while (current_twit != nullptr) {
                recent_twits.push(current_twit);
                current_twit = current_twit->next;
            }
        }

        // 被关注的user发的twit
        if (id_follow_list.find(userId) != id_follow_list.end()) {
            // 遍历被关注的user
            for (auto followed_user: id_follow_list[userId]) {
                // 当前followed_user发过twit
                if (id_twit_list.find(followed_user) != id_twit_list.end()) {
                    Twit* current_twit = id_twit_list[followed_user];
                    while (current_twit != nullptr) {
                        recent_twits.push(current_twit);
                        current_twit = current_twit->next;
                    }
                }
            }
        }
        int count = 0;
        vector<int> result;
        while (count < 10 && !recent_twits.empty()) {
            Twit* twit = recent_twits.top();
            recent_twits.pop();
            result.push_back(twit->twit_id);
            count++;
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            id_follow_list[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // 存在followerId
        if (id_follow_list.find(followerId) != id_follow_list.end()) {
            set<int>& follow_list = id_follow_list[followerId];
            // follow列表中存在followeeId
            if (follow_list.find(followeeId) != follow_list.end()) {
                follow_list.erase(followeeId);
            }
        }
    }
};
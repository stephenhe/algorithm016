class Leaderboard {
    map<int, int, greater<int>> rank_; // 分数 <--> 个数
    unordered_map<int, int> scoremap_; // id <--> 分数
public:
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        --rank_[scoremap_[playerId]];
        scoremap_[playerId]+=score;
        ++rank_[scoremap_[playerId]];
    }
    
    int top(int K) {
        int n = 0;
        int sum = 0;
        for (pair<int, int> scorevalue : rank_) {
            if (scorevalue.second + n < K) {
                n += scorevalue.second;
                sum += scorevalue.first * scorevalue.second;
            }
            else {
                sum += (K - n) * scorevalue.first;
                break;
            }
        }
        return sum;
    }
    
    void reset(int playerId) {
        --rank_[scoremap_[playerId]];
        scoremap_[playerId] = 0;
    }
};


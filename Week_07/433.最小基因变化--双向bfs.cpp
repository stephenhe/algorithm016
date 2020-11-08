/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode-cn.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (52.73%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 17.4K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。
 * 
 * 假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。
 * 
 * 例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
 * 
 * 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
 * 
 * 现在给定3个参数 — start, end,
 * bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回
 * -1。
 * 
 * 注意:
 * 
 * 
 * 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
 * 所有的目标基因序列必须是合法的。
 * 假定起始基因序列与目标基因序列是不一样的。
 * 
 * 
 * 示例 1:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 * 
 * 返回值: 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 * 
 * 返回值: 2
 * 
 * 
 * 示例 3:
 * 
 * 
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 * 
 * 返回值: 3
 * 
 * 
 */

// @lc code=start
class Solution {
    bool check(string gene, queue<string>& q, unordered_set<string>& bankSet, unordered_set<string>& visit, unordered_set<string>& othervisit) {
        char charators[] = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < gene.size(); i++) {
            for (int j = 0; j < 4; j++) {
                if (gene[i] != charators[j]) {
                    char tmp = gene[i];
                    gene[i] = charators[j];

                    if (othervisit.find(gene) != othervisit.end()) {
                        return false;
                    }
                    if (bankSet.find(gene) != bankSet.end() && visit.find(gene) == visit.end()) {
                        visit.insert(gene);
                        q.push(gene);
                    }
                    gene[i] = tmp;
                }
            }
        }
        return true;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.size() < 1 || bankSet.find(end) == bankSet.end()) return -1;
        queue<string>* frontQ = new queue<string>();
        queue<string>* backQ = new queue<string>();
        unordered_set<string>* frontVisit = new unordered_set<string>();
        unordered_set<string>* backVisit = new unordered_set<string>();
        int depth = 0;
        frontQ->push(start);
        frontVisit->insert(start);
        backQ->push(end);
        backVisit->insert(end);
        bankSet.erase(end);
        while (!frontQ->empty() && !backQ->empty()) {
            if (frontQ->size() > backQ->size()) {
                swap(frontQ, backQ);
                swap(frontVisit, backVisit);
            }
            int size = frontQ->size();
            for (int i = 0; i < size; i++) {
                string gene = frontQ->front(); frontQ->pop();
                if (!check(gene, *frontQ, bankSet, *frontVisit, *backVisit)) {
                    return depth+1;
                }
            }
            depth++;
        }

        return -1;
    }
};
// @lc code=end


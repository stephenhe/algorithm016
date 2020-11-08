/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.47%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    62.7K
 * Total Submissions: 143.4K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
class Solution {
    void check(string word, queue<string>& q, unordered_set<string>& wordSet, unordered_set<string>& visitSet) {
        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < 26; j++) {
                char tmp = word[i];
                word[i] = j + 'a';
                if (tmp != j + 'a' && wordSet.find(word) != wordSet.end()) {
                    if (visitSet.find(word) == visitSet.end()) {
                        q.push(word);
                        visitSet.insert(word);
                    }
                }
                word[i] = tmp;
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() < 1) return 0;
        unordered_set<string> wordSet;
        for (int i = 0; i < wordList.size(); i++) {
            wordSet.insert(wordList[i]);
        }
        queue<string>* frontQ = new queue<string>();
        queue<string>* backQ = new queue<string>();
        unordered_set<string>* visitFSet = new unordered_set<string>();
        unordered_set<string>* visitBSet = new unordered_set<string>();
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        wordSet.emplace(beginWord);
        wordSet.emplace(endWord);
        visitFSet->emplace(beginWord);
        visitBSet->emplace(endWord);
        frontQ->push(beginWord);
        backQ->push(endWord);
        int depth = 1;
        while (!frontQ->empty() && !backQ->empty()) {
            if (frontQ->size() > backQ->size()) {
                swap(frontQ, backQ);
                swap(visitFSet, visitBSet);
            }
            int size = frontQ->size();
            for (int m = 0; m < size; m++) {
                string frontW = frontQ->front(); frontQ->pop();
                if (visitBSet->find(frontW) != visitBSet->end())
                    return depth;
                check(frontW, *frontQ, wordSet, *visitFSet);
            }
            if (frontQ->empty()) return 0;
            depth++;
        }
        return depth;
    }
};
// @lc code=end


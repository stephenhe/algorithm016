// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem212.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution
{
    class Trie
    {
    public:
        vector<Trie *> nodes;
        string word;
        Trie() : nodes(26, nullptr), word("")
        {
        }

        void insert(string word)
        {
            Trie *node = this;
            for (char c : word)
            {
                int idx = c - 'a';
                if (node->nodes[idx] == nullptr)
                    node->nodes[idx] = new Trie();
                node = node->nodes[idx];
            }
            node->word = word;
        }

        Trie *findNext(char c)
        {
            int idx = c - 'a';
            return nodes[idx];
        }
    };

    void dps(vector<vector<char>> &board, vector<string> &result, Trie *trie, int i, int j)
    {
        if (board[i][j] == 0)
            return;
        Trie *node = trie->nodes[board[i][j] - 'a'];
        if (node == nullptr)
            return;
        if (node->word.length() > 0)
        {
            result.push_back(node->word);
            node->word = "";
        }

        int tmp = board[i][j];
        board[i][j] = 0;
        if (i > 0)
            dps(board, result, node, i - 1, j);
        if (i < board.size() - 1)
            dps(board, result, node, i + 1, j);
        if (j > 0)
            dps(board, result, node, i, j - 1);
        if (j < board[0].size() - 1)
            dps(board, result, node, i, j + 1);
        board[i][j] = tmp;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;
        if (board.size() < 1)
            return result;
        if (board[0].size() < 1)
            return result;
        Trie *trie = new Trie();
        for (string str : words)
            trie->insert(str);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dps(board, result, trie, i, j);
            }
        }
        return result;
    }
};
// @lc code=end


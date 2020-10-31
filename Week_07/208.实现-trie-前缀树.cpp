// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem208.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
    vector<Trie *> nodes;
    string str;

public:
    /** Initialize your data structure here. */
    Trie() : nodes(26, nullptr), str("")
    {
    }

    /** Inserts a word into the trie. */
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
        node->str = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            int idx = c - 'a';
            if (node->nodes[idx] == nullptr)
                return false;
            node = node->nodes[idx];
        }
        if (node->str != word)
            return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            int idx = c - 'a';
            if (node->nodes[idx] == nullptr)
                return false;
            node = node->nodes[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
private:
    struct DLNode {
        int val;
        DLNode *prev;
        DLNode *next;
        DLNode() : val(-1) {}
        DLNode(int val) : val(val) {}
    };

    DLNode *head;
    DLNode *tail;
    int capacity;
    int size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        head = new DLNode();
        tail = new DLNode();
        head->next = tail;
        tail->prev = head;
        capacity = k;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        DLNode *node = new DLNode(value);
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        DLNode *node = new DLNode(value);
        node->prev = tail->prev;
        tail->prev = node;
        node->prev->next = node;
        node->next = tail;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        DLNode *node = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        delete node;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        DLNode *node = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return tail->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size <= 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size >= capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end


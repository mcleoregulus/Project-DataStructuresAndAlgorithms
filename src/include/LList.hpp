#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>
#include <cstddef>
#include <cassert>
#include "list.hpp"
#include "link.hpp"

const int defaultSize = 100;

// Linked list implementation
template <typename E>
class LList : public List<E>
{
private:
    Link<E> *head; // Pointer to list header
    Link<E> *tail; // Pointer to last element
    Link<E> *curr; // Access to current element
    int cnt;       // Size of list
    void init()
    { // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    void removeall()
    { // Return link nodes to free store
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size = defaultSize) { init(); } // Constructor
    ~LList() { removeall(); }                 // Destructor
    void print() const {
        Link<E> *temp = head->next; // 从第一个有效节点开始（跳过头节点）
        while (temp != NULL)        // 遍历链表
        {
            cout << temp->element << " "; // 输出当前节点的值
            temp = temp->next;                 // 移动到下一个节点
        }
        cout << endl; // 输出换行符，结束打印
    };                       // Print list contents
    void clear()
    {
        removeall();
        init();
    } // Clear list
    // Insert "it" at current position
    void insert(const E &it)
    {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr)
            tail = curr->next; // New tail
        cnt++;
    }
    void append(const E &it)
    { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
    // Remove and return current element
    E remove()
    {
        assert(curr->next != NULL && "No element");
        E it = curr->next->element;  // Remember value
        Link<E> *ltemp = curr->next; // Remember link node
        if (tail == curr->next)
            tail = curr;               // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement the count
        return it;
    }
    void moveToStart() // Place curr at list start
    {
        curr = head;
    }
    void moveToEnd() // Place curr at list end
    {
        curr = tail;
    }
    // Move curr one step left; no change if already at front
    void prev()
    {
        if (curr == head)
            return; // No previous element
        Link<E> *temp = head;
        // March down list until we find the previous element
        while (temp->next != curr)
            temp = temp->next;
        curr = temp;
    }
    // Move curr one step right; no change if already at end
    void next()
    {
        if (curr != tail)
            curr = curr->next;
    }
    int length() const { return cnt; } // Return length
    // Return the position of the current element
    int currPos() const
    {
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    // Move down list to "pos" position
    void moveToPos(int pos)
    {
        assert((pos >= 0) && (pos <= cnt) && "Position out of range");
        curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
    }
    const E &getValue() const
    { // Return current element
        assert(curr->next != NULL && "No value");
        return curr->next->element;
    }
};

#endif // LLIST_HPP
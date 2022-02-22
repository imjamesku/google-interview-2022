#include <queue>
#include <vector>
using namespace std;
/**
 * Time 23mins
 * nodes:
 * to use custom comparator, priority queue needs 3 arguments as template
 * Don't put nullptr into queue, or they won't compare
 */
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct Cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // put all lists into a pq
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (auto* first : lists) {
            if (first != nullptr) {
                pq.push(first);
            }
        }
        // take one node at a time until pq empty
        ListNode* head = new ListNode();
        ListNode* cur = head;
        // cout<<pq.size()<<"\n";
        while (pq.size() > 0) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next != nullptr) {
                pq.push(cur->next);
            }
        }
        return head->next;
    }
};
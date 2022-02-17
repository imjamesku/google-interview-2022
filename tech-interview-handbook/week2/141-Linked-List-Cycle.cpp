#include <unordered_map>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> indices;
        int idx = 0;
        ListNode *cur;
        for (cur = head; cur != nullptr && indices.count(cur) == 0; cur = cur->next) {
            indices[cur] = idx;
            idx++;
        }
        return cur != nullptr;
    }
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (slow == nullptr || fast == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
#include <queue>
#include <set>
#include <vector>
// First attemp: solution currect, but TLE
// binary search tree
using namespace std;
class Node {
   public:
    Node(int _val) : left(nullptr), right{nullptr}, val(_val), count(1), leftCount(0) {}
    Node* left;
    Node* right;
    int val;
    int count;
    int leftCount;
};
class MedianFinder {
   public:
    MedianFinder() {
        root = nullptr;
        totalNodes = 0;
    }

    void addNum(int num) {
        totalNodes++;
        if (root == nullptr) {
            root = new Node(num);
            return;
        }
        addNode(num, root);
    }

    double findMedian() {
        // cout << "total: " << totalNodes << "\n";
        if (totalNodes % 2 == 0) {
            // 4->2, 3   2->1, 2  8->4,5
            int first = totalNodes / 2;
            double val1 = findKth(root, first);
            double val2 = findKth(root, first + 1);
            return (val1 + val2) / 2;
        } else {
            return static_cast<double>(findKth(root, totalNodes / 2 + 1));
        }
    }

   private:
    void addNode(int num, Node* node) {
        if (num > node->val) {
            if (node->right == nullptr) {
                node->right = new Node(num);
            } else {
                addNode(num, node->right);
            }
        } else if (num < node->val) {
            node->leftCount++;
            if (node->left == nullptr) {
                node->left = new Node(num);
            } else {
                addNode(num, node->left);
            }
        } else {
            node->count++;
        }
    }
    int findKth(Node* node, int k) {
        if (k <= node->leftCount) {
            // on left subtree
            return findKth(node->left, k);
        } else if (k <= node->leftCount + node->count) {
            return node->val;
        } else {
            return findKth(node->right, k - node->leftCount - node->count);
        }
    }
    Node* root;
    int totalNodes;
};

struct LargerFirst {
    bool operator()(int a, int b) {
        return a > b;
    }
};
// using heaps
class MedianFinder2 {
   public:
    MedianFinder2() {
    }

    void addNum(int num) {
        lowerHalf.push(num);
        int tmp = lowerHalf.top();
        lowerHalf.pop();
        upperHalf.push(tmp);
        if (upperHalf.size() > lowerHalf.size()) {
            tmp = upperHalf.top();
            upperHalf.pop();
            lowerHalf.push(tmp);
        }
    }

    double findMedian() {
        // cout << "total: " << totalNodes << "\n";
        if ((lowerHalf.size() + upperHalf.size()) % 2 == 0) {
            double first = lowerHalf.top();
            double second = upperHalf.top();
            return (first + second) / 2;
        }
        return lowerHalf.top();
    }

   private:
    priority_queue<int> lowerHalf;                            // max heap
    priority_queue<int, vector<int>, LargerFirst> upperHalf;  // min heap
};

// using binary tree
// property: multiset always insert to the right if value equals
// https://leetcode.com/problems/find-median-from-data-stream/submissions/
class MedianFinder {
   public:
    MedianFinder() : loMid(data.begin()), hiMid(data.end()) {
    }

    void addNum(int num) {
        data.insert(num);
        if (data.size() == 1) {
            loMid = data.begin();
            hiMid = loMid;
        } else if (data.size() % 2 != 0) {
            if (num >= *hiMid) {
                loMid++;
            } else if (num < *loMid) {
                hiMid--;
            } else {
                loMid++;
                hiMid--;
            }
        } else {
            if (num >= *loMid) {
                hiMid++;
            } else {
                loMid--;
            }
        }
    }

    double findMedian() {
        // cout << "total: " << totalNodes << "\n";
        if (data.size() % 2 == 0) {
            return (double)(*loMid + *hiMid) / 2;
        }
        return *loMid;
    }

   private:
    multiset<int> data;
    multiset<int>::iterator loMid;
    multiset<int>::iterator hiMid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
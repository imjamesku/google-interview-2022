#include <iostream>
using std::unique_ptr;
class Node {
   public:
    int val;
    unique_ptr<Node> next{};

    Node(int val) : val(val) {}
};
class ILinkedList {
   public:
    virtual ~ILinkedList() {}
    virtual void add(int) = 0;
    virtual void remove() = 0;
};

class LinkedList {
   private:
    unique_ptr<Node> head{};

   public:
    void addNode(int value) {
        if (!head) {
            head.reset(new Node(value));
        } else {
            auto* newNode = new Node(value);
            newNode->next = std::move(head);
            head.reset(newNode);
        }
    }
    void removeNode() {
        unique_ptr<Node> tmp(std::move(head->next));
        head = (std::move(tmp));
    }
    int getHeadValue() {
        return head->val;
    }
    void display() {
        for (auto cur = head.get(); cur != nullptr; cur = cur->next.get()) {
            std::cout << cur->val << ",";
        }
        std::cout << "\n";
    }
};

int main(void) {
    LinkedList list;
    list.addNode(3);
    list.addNode(2);
    list.addNode(1);
    list.display();
    list.removeNode();
    list.display();

    // std::cout << list.getHeadValue() << std::endl;
}